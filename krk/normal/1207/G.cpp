#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;
const int Maxl = 26;

char tmp[Maxn];
int n;
vector <ii> neigh[Maxn];
map <string, int> ID;
int acc[Maxn];
vector <ii> quer[Maxn];
int cur, nxt[Maxn][Maxl], fal[Maxn];
vector <int> sum[Maxn];
int m;
int res[Maxn];

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int getID(const string &s)
{
    map <string, int>::iterator it = ID.find(s);
    if (it == ID.end()) {
        int siz = ID.size();
        ID.insert(make_pair(s, siz));
        return siz;
    }
    return it->second;
}

void Precompute()
{
    fill((int*)nxt, (int*)nxt + Maxn * Maxl, -1);
    fill(fal, fal + Maxn, -1);
    cur = 1;
    for (map <string, int>::iterator it = ID.begin(); it != ID.end(); it++) {
        int pnt = 0;
        for (int i = 0; i < it->first.size(); i++) {
            if (nxt[pnt][it->first[i] - 'a'] == -1)
                nxt[pnt][it->first[i] - 'a'] = cur++;
            pnt = nxt[pnt][it->first[i] - 'a'];
        }
        sum[pnt].push_back(it->second);
    }
    for (int i = 0; i < Maxl; i++)
        if (nxt[0][i] == -1) nxt[0][i] = 0;
    vector <int> Q;
    for (int i = 0; i < Maxl; i++)
        if (nxt[0][i] != 0) {
            fal[nxt[0][i]] = 0;
            Q.push_back(nxt[0][i]);
        }
    for (int i = 0; i < Q.size(); i++) {
        int v = Q[i];
        for (int j = 0; j < Maxl; j++)
            if (nxt[v][j] != -1) {
                int myfail = fal[v];
                while (nxt[myfail][j] == -1)
                    myfail = fal[myfail];
                myfail = nxt[myfail][j];
                fal[nxt[v][j]] = myfail;
                for (int z = 0; z < sum[myfail].size(); z++)
                    sum[nxt[v][j]].push_back(sum[myfail][z]);
                Q.push_back(nxt[v][j]);
            }
    }
}

int getNext(int state, int ch) { return nxt[state][ch] != -1? nxt[state][ch]: nxt[state][ch] = getNext(fal[state], ch); }

void Solve(int v, int s)
{
    for (int i = 0; i < sum[s].size(); i++)
        acc[sum[s][i]]++;
    for (int i = 0; i < quer[v].size(); i++) {
        ii p = quer[v][i];
        res[p.second] = acc[p.first];
    }
    for (int i = 0; i < neigh[v].size(); i++)
        Solve(neigh[v][i].first, getNext(s, neigh[v][i].second));
    for (int i = 0; i < sum[s].size(); i++)
        acc[sum[s][i]]--;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            char ch; scanf(" %c", &ch);
            neigh[0].push_back(ii(i, ch - 'a'));
        } else if (typ == 2) {
            int par; char ch; scanf("%d %c", &par, &ch);
            neigh[par].push_back(ii(i, ch - 'a'));
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int ind; scanf("%d", &ind);
        string s; Read(s);
        quer[ind].push_back(ii(getID(s), i));
    }
    Precompute();
    Solve(0, 0);
    for (int i = 0; i < m; i++)
        printf("%d\n", res[i]);
    return 0;
}