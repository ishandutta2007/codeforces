#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <ll, int> lli;
 
const int Maxn = 200005;

bool prime[Maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int T;
int n;
ll cur[Maxn];
vector <int> V[Maxn];
vector <int> seq;
ll asked;
 
ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }
 
ll Ask(int a, int b)
{
    printf("? %d %d\n", a, b); fflush(stdout);
    ll res; scanf("%I64d", &res);
    return res;
}

void Print()
{
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %I64d", cur[i]);
    printf("\n"); fflush(stdout);
}
 
int main()
{
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i])
        for (int j = i + i; j < Maxn; j += i)
            prime[j] = false;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        seq.resize(n);
        for (int i = 1; i <= n; i++) {
            cur[i] = 0;
            seq[i - 1] = i;
        }
        if (n <= 100) {
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++) {
                    ll g = Ask(i, j);
                    cur[i] = gcd(cur[i], g);
                    cur[j] = gcd(cur[j], g);
                }
            if (n == 3) {
                vector <lli> tmp;
                for (int i = 1; i <= n; i++)
                    tmp.push_back(lli(cur[i], i));
                sort(tmp.begin(), tmp.end());
                if (tmp.back().first - tmp[0].first != 2)
                    cur[tmp.back().second] = (tmp[0].first + tmp[1].first) / 2;
            }
            Print();
            continue;
        }
        shuffle(seq.begin(), seq.end(), rng);
        for (int i = 0; i < 100; i++)
            for (int j = i + 1; j < 100; j++) {
                ll g = Ask(seq[i], seq[j]);
                cur[seq[i]] = gcd(cur[seq[i]], g);
                cur[seq[j]] = gcd(cur[seq[j]], g);
            }
        int mx = -1;
        for (int i = 0; i < 100; i++)
            if (prime[cur[seq[i]]] && (mx == -1 || cur[seq[i]] > cur[mx])) mx = seq[i];
        for (int i = 100; i < n; i++) {
            ll g = Ask(mx, seq[i]);
            cur[seq[i]] = g / cur[mx];
        }
        for (int i = 0; i < Maxn; i++)
            V[i].clear();
        for (int i = 1; i <= n; i++)
            V[cur[i]].push_back(i);
        int pnt = 0;
        while (cur[seq[pnt]] % cur[mx] == 0) pnt++;
        for (int i = 0; i < Maxn; i++) {
            assert(V[i].size() <= 2);
            if (V[i].size() > 1) {
                int a = V[i][0], b = V[i][1];
                if (a == seq[pnt] || Ask(a, seq[pnt]) % cur[mx] == 0)
                    cur[a] *= cur[mx];
                else cur[b] *= cur[mx];
            }
        }
        Print();
    }
    return 0;
}