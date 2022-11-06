#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
pair<int, int> b[N];
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
        long long ans = 0;
        priority_queue<long long> pq;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            ans += a[i];
        }
        for(int i = k + 1; i <= n; i ++) pq.push(a[i] + i - n);
        for(int i = k; i > 0; i --)
        {
            pq.push(a[i] - n + i);
            ans = ans - k + i - pq.top();
            pq.pop();
        }
        cout << ans << "\n";
    }

}