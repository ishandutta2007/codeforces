#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FFOR(i,a,b) for (int i = a; i >= b; i--)
const int ma = 1e4+10;
using namespace std;
int a[ma];
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		int b[3] = {0};
		int n; cin>>n;
		FOR(i,1,n)
		{
			int x; cin>>x;
			x%=3;
			b[x]++; 
		}
		int c0 = 0,c1= 0,c2= 0;
		c0 = b[0];c1 = b[1];c2 = b[2];
		int t = n/3;
		int sum = 0;
			if(c0>t)
			{
				sum+=(c0-t);
				c1 += (c0-t);
				c0 = t; 
			}
			if(c1>t)
			{
				sum+=(c1-t);
				c2 += (c1-t);
				c1 = t; 
			}
			if(c2>t)
			{
				sum+=(c2-t);
				c0 += (c2-t);
				c2 = t; 
			}
			if(c0>t)
			{
				sum+=(c0-t);
				c1 += (c0-t);
				c0 = t; 
			}
			
		
		cout<<sum<<'\n';
		
		
	}
}