#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 10000000000000000LL;
const int Maxn = 100005;

int k1, k2, k3;
ll t1, t2, t3;
int n;
ll c[Maxn];
ll tim;
queue <pair <int, ll> > Q[3];
queue <int> W[3], N;
int pnt = 1;
ll res;

void Live()
{
     while (pnt <= n && c[pnt] <= tim) W[0].push(pnt++);
     while (!Q[0].empty() && Q[0].front().second + t1 <= tim) {
           W[1].push(Q[0].front().first); Q[0].pop();
     }
     while (!W[0].empty() && Q[0].size() < k1) {
           Q[0].push(make_pair(W[0].front(), tim)); W[0].pop();
     }
     while (!Q[1].empty() && Q[1].front().second + t2 <= tim) {
           W[2].push(Q[1].front().first); Q[1].pop();
     }
     while (!W[1].empty() && Q[1].size() < k2) {
           Q[1].push(make_pair(W[1].front(), tim)); W[1].pop();
     }
     while (!Q[2].empty() && Q[2].front().second + t3 <= tim) {
           res = max(res, tim - c[Q[2].front().first]); Q[2].pop();
     }
     while (!W[2].empty() && Q[2].size() < k3) {
           Q[2].push(make_pair(W[2].front(), tim)); W[2].pop();
     }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> k1 >> k2 >> k3;
    cin >> t1 >> t2 >> t3;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    while (pnt <= n || !Q[0].empty() || !Q[1].empty() || !Q[2].empty()) {
                                     tim = Inf;
                                     if (pnt <= n) tim = min(tim, c[pnt]);
                                     if (!Q[0].empty()) tim = min(tim, Q[0].front().second + t1);
                                     if (!Q[1].empty()) tim = min(tim, Q[1].front().second + t2);
                                     if (!Q[2].empty()) tim = min(tim, Q[2].front().second + t3);
                                     Live();
    }
    cout << res << endl;
    return 0;
}