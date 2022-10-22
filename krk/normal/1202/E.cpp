#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxl = 26;

char tmp[Maxn];
string T;
int n;
string S[Maxn];
int cur, nxt[Maxn][Maxl], fal[Maxn], sum[Maxn];
int L[Maxn];
ll res;

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

void Precompute()
{
    fill((int*)nxt, (int*)nxt + Maxn * Maxl, -1);
    fill(fal, fal + Maxn, -1);
    fill(sum, sum + Maxn, 0);
    cur = 1;
    for (int ind = 0; ind < n; ind++) {
        int pnt = 0;
        for (int i = 0; i < S[ind].length(); i++) {
            if (nxt[pnt][S[ind][i] - 'a'] == -1)
                nxt[pnt][S[ind][i] - 'a'] = cur++;
            pnt = nxt[pnt][S[ind][i] - 'a'];
        }
        sum[pnt]++;
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
                sum[nxt[v][j]] += sum[myfail];
                Q.push_back(nxt[v][j]);
            }
    }
}

int getNext(int state, int ch)
{
    while (nxt[state][ch] == -1)
        state = fal[state];
    return nxt[state][ch];
}

int main()
{
    Read(T);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        Read(S[i]);
    Precompute();
    int state = 0;
    for (int i = 0; i < T.length(); i++) {
        state = getNext(state, T[i] - 'a');
        L[i] = sum[state];
    }
    for (int i = 0; i < n; i++)
        reverse(S[i].begin(), S[i].end());
    Precompute();
    state = 0;
    for (int i = int(T.length()) - 1; i > 0; i--) {
        state = getNext(state, T[i] - 'a');
        res += ll(sum[state]) * L[i - 1];
    }
    printf("%I64d\n", res);
    return 0;
}