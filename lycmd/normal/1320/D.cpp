#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,MOD=998244353;
int n,q,c[N],pw[N],h[N][2];
string s;
int gethash(int l,int r){
	return(h[r][l&1]-h[l-1][l&1]*pw[c[r]-c[l-1]]%MOD+MOD)%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>s>>q,pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*3%MOD,c[i]=c[i-1]+(~s[i-1]&1),
		s[i-1]&1?(h[i][0]=h[i-1][0],h[i][1]=h[i-1][1]):
		(h[i][0]=(h[i-1][0]*3+1+(i&1))%MOD,
		h[i][1]=(h[i-1][1]*3+1+(~i&1))%MOD);
	while(q--){
		int x,y,l;cin>>x>>y>>l;
		cout<<(gethash(x,x+l-1)==gethash(y,y+l-1)?"Yes\n":"No\n");
	}
}