#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FFOR(i,a,b) for (int i = a; i >= b; i--)
const int ma = 55;
using namespace std;
int a[ma];
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		int n; cin>>n;
		FOR(i,1,n) cin>>a[i];
		int sum = 0; 
		FOR(i,2,n)
		{
			int minn = min(a[i],a[i-1]);
			int maxn = max(a[i],a[i-1]);
			if(maxn<=2*minn) continue;
			else 
			{
				while(maxn>2*minn)
				{
					sum++;
					minn*=2;
				}
			}
		}
		cout<<sum<<'\n';
	}
}