#include <bits/stdc++.h>
using namespace std;
#define int long long
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define endl '\n'
const int N = 2e5+10,inf = 1e9+10,mod = 1e9+7;
int q,w,e;
void solve()
{
	int n,a,b; cin>>n>>a>>b;
	string s; cin>>s;
	if(b>=0) cout<<n*(a+b)<<endl;
	else
	{
		q=w=e=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				e++, q+=a;
				if(s[i-1]!='0') q+=b;
			}
		}
		q+=(n-e)*a+b;
		e=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				e++, w+=a;
				if(s[i-1]!='1') w+=b;
			}
		}
		w+=(n-e)*a+b;
		cout<<max(q,w)<<endl;
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