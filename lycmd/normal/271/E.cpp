#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,g,ans;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;n--;)
		cin>>a,g=__gcd(g,a-1);
	while(~g&1)
		g>>=1;
	for(int i=1;i*i<=g;i++)
		if(g%i==0){
			for(int j=i;j<=m;j<<=1)
				ans+=m-j;
			if(i*i<g)
				for(int j=g/i;j<=m;j<<=1)
					ans+=m-j;
		}
	cout<<ans<<"\n";
}