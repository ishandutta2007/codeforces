#include <bits/stdc++.h>
#include <unordered_map>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define X first
#define Y second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
const int N = 110;
set<pii> invalid, vis;
vector<int> rcnt[300010];
bool ok(int x, int y) 
{
    if (x > y) swap(x, y);
    if (invalid.find(pii(x, y)) == invalid.end()) return true;
    else return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T --) 
    {
    	invalid.clear();
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        unordered_map<int, int> cnt;
        rep0(i, n)
        {
            cin >> a[i];
            cnt[a[i]] ++;
        }
        
        while(q --) 
        {
            int x, y;
            cin >> x >> y;
            invalid.insert(mp(x, y));
        }
        rep0(i, n + 1) rcnt[i].clear();
        for (auto t : cnt) 
            rcnt[t.Y].pb(t.X);
        vector<int> cntt;
        rep0(i, n)
            if (rcnt[i].size() > 0) 
                cntt.pb(i);
        ll ans = 0;
        int m = cntt.size();
        rep0(i, m)
        	rep(j, i, m - 1)
        	{
                vector<int> v1, v2;
                int cnt1 = cntt[i]; 
                int cnt2 = cntt[j];
                for (auto t : rcnt[cnt1]) v1.pb(t);
                for (auto t : rcnt[cnt2]) v2.pb(t);
                sort(v1.begin(), v1.end());
                sort(v2.begin(), v2.end());
                reverse(v1.begin(), v1.end());
                reverse(v2.begin(), v2.end());
                vis.clear();
                priority_queue<pair<int, pii> > Q;
                vis.emplace(0, 0);
                Q.emplace(pair<int, pair<int, int> > (v1[0] + v2[0], mp(0, 0)));
                while(!Q.empty()) 
                {
                    auto now = Q.top();
                    Q.pop();
                    int val = now.X;
                    int n1 = now.Y.X, n2 = now.Y.Y;
                    int r1 = v1[n1], r2 = v2[n2];
                    if (ok(r1, r2)) 
                        if (i != j || n1 != n2)
                        {
                            ans = max(ans, 1LL * (r1 + r2) * (cnt1 + cnt2));
                            break;
                        }
                    if (n1 + 1 < v1.size() && vis.find(mp(n1 + 1, n2)) == vis.end()) 
                        if (i != j || n1 + 1 <= n2) 
                        {
                            vis.emplace(n1 + 1, n2);
                            Q.push(pair<int, pair<int, int> > (v1[n1 + 1] + v2[n2], mp(n1 + 1, n2)));
                        }
                    
                    if (n2 + 1 < v2.size() && vis.find(mp(n1, n2 + 1)) == vis.end()) 
                        if (i != j || n1 <= n2 + 1) 
                        {
                            vis.emplace(n1, n2 + 1);
                            Q.push(pair<int, pair<int, int> > (v1[n1] + v2[n2 + 1], mp(n1, n2 + 1)));
                        }
                    
                }
            }
        
        cout << ans << '\n';
    }
}