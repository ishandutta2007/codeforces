#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXM = 210;
const int MAXC = 2100;

int N, M;
string S;

vector <int> child[MAXM];
int l[MAXM], r[MAXM], t[MAXM]; // fill on instantiation
int h[MAXM], w[MAXM]; // fill on solve
int hshift[MAXM], wshift[MAXM]; // fill on render
char board[MAXC][MAXC];

// t: 0=input, 1=expr, 2=term, 3=atom, 4=str

void prep (int ind)
{
    int lcur = l[ind], rcur = r[ind], tcur = t[ind];

    if (tcur == 0)
    {
        // input
        l[M] = lcur;
        r[M] = rcur;
        t[M] = 1;
        child[ind].push_back(M);

        int mcur = M;
        M++;
        prep (mcur);
        h[ind] = h[mcur];
        w[ind] = w[mcur] + 6;
    }
    else if (tcur == 1)
    {
        // expr

        int pcount = 0;
        int llo = lcur;
        vector <pair <int, int> > v;
        for (int i = lcur; i <= rcur; i++)
        {
            if (S[i] == '(') pcount++;
            if (S[i] == ')') pcount--;

            if (pcount == 0 && S[i] == '|')
            {
                v.push_back (make_pair (llo, i - 1));
                llo = i + 1;
            }
        }
        v.push_back (make_pair (llo, rcur));

        for (int i = 0; i < v.size(); i++)
        {
            l[M] = v[i].first;
            r[M] = v[i].second;
            t[M] = 2;
            child[ind].push_back(M);

            M++;

            prep (M - 1);
        }

        if (v.size() == 1)
        {
            int cloc = child[ind][0];
            h[ind] = h[cloc];
            w[ind] = w[cloc];
        }
        else
        {
            int htot = 0, whi = 0;
            for (int cloc : child[ind])
            {
                htot += h[cloc] + 1;
                whi = max (whi, w[cloc]);
            }
            htot--;

            h[ind] = htot;
            w[ind] = whi + 6;
        }
    }
    else if (tcur == 2)
    {
        // term

        vector <pair <int, int> > v;
        int llo = lcur;
        int pcount = 0;
        for (int i = lcur; i <= rcur; i++)
        {
            if (S[i] == '(') pcount++;
            if (S[i] == ')')
            {
                pcount--;
                if (!pcount)
                {
                    v.push_back (make_pair (llo, i));
                    llo = i + 1;
                }
            }

            if (!pcount)
            {
                if (S[i] == '+' || S[i] == '?' || S[i] == '*')
                {
                    v[v.size() - 1].second++;
                    llo++;
                }
                else if (S[i] >= 'A' && S[i] <= 'Z')
                {
                    v.push_back (make_pair (llo, i));
                    llo = i + 1;
                }
            }
        }

        vector <pair <int, int> > vcat;
        for (int i = 0; i < v.size(); i++)
        {
            int lo = v[i].first, hi = v[i].second;
            if (lo == hi)
            {
                int nv = i;
                while (nv + 1 < v.size() && v[nv+1].first == v[nv+1].second)
                    nv++;
                vcat.push_back (make_pair (lo, v[nv].second));
                i = nv;
            }
            else
            {
                vcat.push_back (make_pair (lo, hi));
            }
        }

        int wtot = 0, hhi = 0;
        for (int i = 0; i < vcat.size(); i++)
        {
            l[M] = vcat[i].first;
            r[M] = vcat[i].second;
            t[M] = 3;
            child[ind].push_back(M);

            M++;

            prep (M - 1);
        }

        for (int cloc : child[ind])
        {
            wtot += w[cloc] + 2;
            hhi = max (hhi, h[cloc]);
        }
        h[ind] = hhi;
        w[ind] = wtot - 2;
    }
    else if (tcur == 3)
    {
        // atom
        char c = S[rcur];
        if (c == ')')
        {
            l[M] = lcur + 1;
            r[M] = rcur - 1;
            t[M] = 1;
            child[ind].push_back(M);

            int mcur = M;
            M++;

            prep (mcur);
            h[ind] = h[mcur];
            w[ind] = w[mcur];
        }
        else if (c == '+')
        {
            l[M] = lcur;
            r[M] = rcur - 1;
            t[M] = 3;
            child[ind].push_back(M);

            int mcur = M;
            M++;

            prep (mcur);
            h[ind] = h[mcur] + 2;
            w[ind] = w[mcur] + 6;
        }
        else if (c == '?')
        {
            l[M] = lcur;
            r[M] = rcur - 1;
            t[M] = 3;
            child[ind].push_back(M);

            int mcur = M;
            M++;

            prep (mcur);
            h[ind] = h[mcur] + 3;
            w[ind] = w[mcur] + 6;
        }
        else if (c == '*')
        {
            l[M] = lcur;
            r[M] = rcur - 1;
            t[M] = 3;
            child[ind].push_back(M);

            int mcur = M;
            M++;

            prep (mcur);
            h[ind] = h[mcur] + 5;
            w[ind] = w[mcur] + 6;
        }
        else
        {
            l[M] = lcur;
            r[M] = rcur;
            t[M] = 4;
            child[ind].push_back(M);

            int mcur = M;
            M++;

            prep (mcur);
            h[ind] = h[mcur];
            w[ind] = w[mcur];
        }
    }
    else
    {
        // str
        h[ind] = 3;
        w[ind] = (rcur - lcur + 1) + 4;
    }
}

void hput (int a, int b, int ind, char c)
{
    board[a+hshift[ind]][b+wshift[ind]] = c;
}

void render (int ind)
{
    int lcur = l[ind], rcur = r[ind], tcur = t[ind];
    //cout << lcur << " " << rcur << " " << tcur << " " << hshift[ind] << " " << wshift[ind] << "\n";

    if (tcur == 0)
    {
        // input
        int cc = child[ind][0];
        hshift[cc] = hshift[ind];
        wshift[cc] = wshift[ind] + 3;
        render (cc);

        hput (1, 0, ind, 'S');
        hput (1, 1, ind, '-');
        hput (1, 2, ind, '>');
        hput (1, w[ind] - 3, ind, '-');
        hput (1, w[ind] - 2, ind, '>');
        hput (1, w[ind] - 1, ind, 'F');
    }
    else if (tcur == 1)
    {
        // expr
        int hcur = 0, hprev = -1;
        if (child[ind].size() == 1)
        {
            int cloc = child[ind][0];
            hshift[cloc] = hshift[ind];
            wshift[cloc] = wshift[ind];
            render (cloc);
        }
        else
        for (int cloc : child[ind])
        {
            hshift[cloc] = hshift[ind] + hcur;
            wshift[cloc] = wshift[ind] + 3;
            render (cloc);

            if (hprev != -1)
            {
                for (int i = hprev + 1; i <= hcur; i++)
                {
                    hput (i, 0, ind, '|');
                    hput (i, w[ind] - 1, ind, '|');
                }
            }

            hput (hcur + 1, 0, ind, '+');
            hput (hcur + 1, 1, ind, '-');
            hput (hcur + 1, 2, ind, '>');
            for (int i = w[cloc] + 3; i <= w[ind] - 3; i++)
                hput (hcur + 1, i, ind, '-');
            hput (hcur + 1, w[ind] - 2, ind, '>');
            hput (hcur + 1, w[ind] - 1, ind, '+');
            hprev = hcur + 1;
            hcur = hcur + 1 + h[cloc];
        }
    }
    else if (tcur == 2)
    {
        // term
        int wcur = 0;
        for (int i = 0; i < child[ind].size(); i++)
        {
            int cloc = child[ind][i];
            hshift[cloc] = hshift[ind];
            wshift[cloc] = wshift[ind] + wcur;
            render (cloc);

            wcur += w[cloc] + 2;
            if (i + 1 < child[ind].size())
            {
                hput (1, wcur - 2, ind, '-');
                hput (1, wcur - 1, ind, '>');
            }
        }
    }
    else if (tcur == 3)
    {
        // atom
        char c = S[rcur];
        int cc = child[ind][0];
        int cloc = cc;
        if (c == ')')
        {
            hshift[cc] = hshift[ind];
            wshift[cc] = wshift[ind];
            render (cc);
        }
        else if (c == '+')
        {
            hshift[cc] = hshift[ind];
            wshift[cc] = wshift[ind] + 3;
            render (cc);

            hput (1, 0, ind, '+');
            hput (1, 1, ind, '-');
            hput (1, 2, ind, '>');
            hput (1, w[ind] - 3, ind, '-');
            hput (1, w[ind] - 2, ind, '>');
            hput (1, w[ind] - 1, ind, '+');

            for (int i = 2; i < h[ind] - 1; i++)
            {
                hput (i, 0, ind, '|');
                hput (i, w[ind] - 1, ind, '|');
            }

            hput (h[ind] - 1, 0, ind, '+');
            hput (h[ind] - 1, 1, ind, '<');
            hput (h[ind] - 1, w[ind] - 1, ind, '+');
            for (int i = 2; i < w[ind] - 1; i++)
                hput (h[ind] - 1, i, ind, '-');
        }
        else if (c == '?')
        {
            hshift[cc] = hshift[ind] + 3;
            wshift[cc] = wshift[ind] + 3;
            render (cc);

            hput (4, 0, ind, '+');
            hput (4, 1, ind, '-');
            hput (4, 2, ind, '>');
            hput (4, w[ind] - 3, ind, '-');
            hput (4, w[ind] - 2, ind, '>');
            hput (4, w[ind] - 1, ind, '+');

            for (int i = 2; i < 4; i++)
            {
                hput (i, 0, ind, '|');
                hput (i, w[ind] - 1, ind, '|');
            }

            hput (1, 0, ind, '+');
            hput (1, w[ind] - 2, ind, '>');
            hput (1, w[ind] - 1, ind, '+');
            for (int i = 1; i < w[ind] - 2; i++)
                hput (1, i, ind, '-');
        }
        else if (c == '*')
        {
            hshift[cc] = hshift[ind] + 3;
            wshift[cc] = wshift[ind] + 3;
            render (cc);

            hput (4, 0, ind, '+');
            hput (4, 1, ind, '-');
            hput (4, 2, ind, '>');
            hput (4, w[ind] - 3, ind, '-');
            hput (4, w[ind] - 2, ind, '>');
            hput (4, w[ind] - 1, ind, '+');

            for (int i = 2; i < 4; i++)
            {
                hput (i, 0, ind, '|');
                hput (i, w[ind] - 1, ind, '|');
            }

            hput (1, 0, ind, '+');
            hput (1, w[ind] - 2, ind, '>');
            hput (1, w[ind] - 1, ind, '+');
            for (int i = 1; i < w[ind] - 2; i++)
                hput (1, i, ind, '-');

            for (int i = 5; i < h[ind] - 1; i++)
            {
                hput (i, 0, ind, '|');
                hput (i, w[ind] - 1, ind, '|');
            }
            hput (h[ind] - 1, 0, ind, '+');
            hput (h[ind] - 1, 1, ind, '<');
            hput (h[ind] - 1, w[ind] - 1, ind, '+');
            for (int i = 2; i < w[ind] - 1; i++)
                hput (h[ind] - 1, i, ind, '-');
        }
        else
        {
            hshift[cc] = hshift[ind];
            wshift[cc] = wshift[ind];
            render (cc);
        }
    }
    else
    {
        // str
        hput (0, 0, ind, '+');
        hput (1, 0, ind, '+');
        hput (2, 0, ind, '+');
        hput (0, w[ind] - 1, ind, '+');
        hput (1, w[ind] - 1, ind, '+');
        hput (2, w[ind] - 1, ind, '+');
        for (int i = 1; i < w[ind] - 1; i++)
        {
            hput (0, i, ind, '-');
            hput (2, i, ind, '-');
        }
        for (int i = 0; i < r[ind] - l[ind] + 1; i++)
            hput (1, i + 2, ind, S[i+l[ind]]);
    }
}

void gogo()
{
    cin >> S;
    N = S.length();
    for (int i = 0; i < MAXC; i++)
        for (int j = 0; j < MAXC; j++)
            board[i][j] = ' ';

    l[0] = 0;
    r[0] = N - 1;
    t[0] = 0;
    M = 1;

    prep (0);

    render (0);
    cout << h[0] << " " << w[0] << "\n";
    for (int i = 0; i < h[0]; i++)
    {
        for (int j = 0; j < w[0]; j++)
            cout << board[i][j];
        cout << "\n";
    }
}

int main()
{
    gogo();
}