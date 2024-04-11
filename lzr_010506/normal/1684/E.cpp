#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], cnt[N];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i <= n + n; i ++) cnt[i] = 0;
        k = min(k, n);
        map<int, int> mp;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            if(a[i] > n)
            {
                if(mp[a[i]] == 0) a[i] = mp[a[i]] = n + i;
                else a[i] = mp[a[i]];
            }
            cnt[a[i]] ++;
        }
        int res = k + 1, pos = n;
        for(int i = 0; i <= 2 * n; i ++)
        {
            if(cnt[i]) continue;
            res --;
            if(res == 0)
            {
                pos = i;
                break;
            }
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = pos; i <= 2 * n; i ++)
            if(cnt[i]) pq.push(cnt[i]);
        bool flag = 0;
        for(int i = 1; i <= k; i ++)
        {
            if(pq.empty()) {flag = 1; break;}
            int cur = pq.top();
            pq.pop();
            if(cur > 1) pq.push(cur - 1);
        }
        if(!flag)cout << min(n, (int)pq.size()) << "\n";
        else cout << "0\n";
    }
}