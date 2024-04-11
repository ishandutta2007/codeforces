#include<bits/stdc++.h>
using namespace std;
typedef unsigned ui;
int const N=100000010;
ui n,a,b,c,d,ans;
bitset<N>vis;
ui f(ui x){
	return a*x*x*x+b*x*x+c*x+d;
}
ui solve(int x){
	ui res=0;
	for(long long i=x;i<=n;i*=x)
		res+=n/i*f(x);
	return res;
}
signed main(){
	cin>>n>>a>>b>>c>>d;
	ans=(n>1)*solve(2)+(n>2)*solve(3);
	for(int i=5;i<=n;i++)
		if(i%2&&i%3&&!vis[i/3]){
			ans+=solve(i);
			if(1ll*i*i<=n)
				for(int j=i*i;j<=n;j+=i)
					if(j%2&&j%3)
						vis.set(j/3);
		}
	cout<<ans<<"\n";
	return 0;
}