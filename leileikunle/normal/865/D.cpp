#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define x first
#define y second
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
const int N = 4e5+10;


void solve() {
	int n; cin>>n;
	priority_queue<int> q;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		q.push(-x);
		q.push(-x);
		ans += x + q.top();
		q.pop();
	}
	cout<<ans<<endl;
}
signed main()
{
    int tt = 1; 
//	cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}