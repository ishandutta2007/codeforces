//

#include <bits/stdc++.h>
#define int long long
#define very_fast std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
signed main()
{
	very_fast;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		up(i,1,n)
		{
			up(j,1,i)
			{
				cout<<'(';
			}
			up(j,1,i)cout<<')';
			up(j,i+1,n)cout<<"()";
			cout<<'\n';
		}
		cout<<'\n';
	}
}//
//