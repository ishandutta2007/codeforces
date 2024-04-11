#include <bits/stdc++.h>
using namespace std;
#define int long long
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define endl '\n'
const int N = 2e5+10,inf = 1e9+10,mod = 1e9+7;

void solve()
{
	int n; cin>>n;
	if(n==1) cout<<1<<endl;
	else
	{
		int q=1,w=1,e=1;
		while(q<n)
		{
			w+=2;
			q+=w;
			e++;
		}
		cout<<e<<endl;
	}
} 
signed main()
{
    int tt=1;
    cin>>tt; 
    while(tt--)
    {
    	solve();
	}
    return 0;
}