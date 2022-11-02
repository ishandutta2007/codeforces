#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 10;

int type[N];
int val[N];
int v[N][3];
set<pair<int, int> > best;

int main()
{
    ios_base::sync_with_stdio(0);

    int s[3];
    for (int j = 0; j < 3; j++)
        s[j] = 0;
    int od = 0;
    fill(val, val + N, -1);
    for (int i = 0; i < N; i++)
        v[i][0] = v[i][1] = v[i][2] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        type[i] = a;
        if (!a)
        {
            int add = 0;
            while (add < 3 && best.size())
            {
                int v = best.begin()->first;
                int p = best.begin()->second;
                best.erase(best.begin());
                val[p] = od;
                s[od]++;
                add++;
                od++;
                od %= 3;
            }
            for (int j = 0; j < 3; j++)
                if (s[j])
                    v[i][j] = 1;
            best.clear();
            s[0] = s[1] = s[2] = 0;
        }
        else
        {
            best.insert(pair<int, int> (-a, i));
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 0)
        {
            int s = v[i][0] + v[i][1] + v[i][2];
            cout << s;
            if (s)
                cout << " ";
            if (v[i][0])
            {
                cout << "popStack";
                if (v[i][1] + v[i][2])
                    cout << " ";
            }
            if (v[i][1])
            {
                cout << "popQueue";
                if (v[i][2])
                    cout << " ";
            }
            if (v[i][2])
                cout << "popBack";
            cout << endl;
        }
        else
        {
            if (val[i] == 0)
                cout << "pushStack";
            if (val[i] == 1)
                cout << "pushQueue";
            if (val[i] == 2)
                cout << "pushBack";
            if (val[i] == -1)
                cout << "pushFront";
            cout << endl;
        }
    }
    //cout << endl;


    return 0;
}