#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int INF = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e6 + 100;
const int64 MOD = 1000000007;

vector<vi> D;
int L[10];

int64 VAL[MAXN];
int64 LEN[MAXN];

int64 mpow(int64 v, int64 l)
{
    if (l == 0)
        return 1LL;
    int64 r = mpow(v, l / 2);
    r = (r * r) % MOD;
    if (l & 1)
        r = (r * v) % MOD;
    return r;
}

void solve(int p)
{
    int64 val = 0;
    int64 pot = 1;
    for (int i = D[p].size() - 1; i >= 0; --i)
    {
        int v = D[p][i];
        //DB(v);

        if (v <= 0)
        {
            val = (val + (-D[p][i]) * pot) % MOD;
            pot = (pot * 10) % MOD;
        }
        else
        {
            val = (val + VAL[v] * pot) % MOD;
            pot = (pot * LEN[v]) % MOD;
        }
    }
    VAL[p] = val;
    LEN[p] = pot;
}

int main()
{
    int q;
    string W;
    cin >> W >> q;

    D.push_back(vi());
    for (int i = 0; i < (int)W.length(); ++i)
        D[0].push_back(-(W[i] - '0'));

    for (int i = 0; i < q; ++i)
    {
        cin >> W;
        D.push_back(vi());
        int n = W[0] - '0';

        for (int j = 3; j < (int)W.length(); ++j)
            D[i + 1].push_back(-(W[j] - '0'));

        for (int j = L[n]; j <= i; ++j)
            for (int k = 0; k < (int)D[j].size(); ++k)
                if (n == (int)(-D[j][k]))
                    D[j][k] = (int64)(i + 1);
        L[n] = i + 1;
    }
    /*
    for (int i = 0; i <= q; ++i)
    {
        for (int j = 0; j < (int)D[i].size(); ++j)
            cout << D[i][j] << " ";
        cout << endl;
    }
    */

    for (int i = q; i >= 0; --i)
        solve(i);

    cout << VAL[0] << endl;
}