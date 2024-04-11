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
		int f[4];
		cin>>f[1]>>f[2]>>f[3];
		sort(f+1,f+3+1);
		cin>>m;
		if(m<=f[1]+f[2]+f[3]-3&&m>=f[3]-f[2]-f[1]-1)cout<<"YES\n";
		else cout<<"NO\n";
	}
}//sakura tears
//