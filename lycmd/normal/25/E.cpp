#include<bits/stdc++.h>
using namespace std;
int const N=300010,B=233,MOD=998244353;
int ans=3*N,pw[N];
struct node{
	int n,h[N];
	string s;
	void calc(){
		for(int i=1;i<=n;i++)
			h[i]=(1ll*h[i-1]*B%MOD+s[i])%MOD;
	}
	void init(){
		cin>>s,n=s.size(),s=" "+s,calc();
	}
	int hash(int l,int r)const{
		return(h[r]-1ll*h[l-1]*pw[r-l+1]%MOD+MOD)%MOD;
	}
	node(int a=0,const string&b=" "):n(a),s(b){calc();}
};
node a[3];
int cmp(const node&a1,int l1,int r1,const node&a2,int l2,int r2){
	return a1.hash(l1,r1)==a2.hash(l2,r2);
}
node merge(const node&a,const node&b){
	int n=a.n,m=b.n;
	for(int i=1;i<=n-m+1;i++)
		if(cmp(a,i,i+m-1,b,1,m))
			return a;
	for(int i=min(n,m);i>=0;i--)
		if(cmp(a,n-i+1,n,b,1,i))
			return node(n+m-i,a.s+b.s.substr(i+1));
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		pw[i]=i?1ll*pw[i-1]*B%MOD:1;
	for(int i=0;i<3;i++)
		a[i].init();
	vector<int>p={0,1,2};
	do
		ans=min(ans,merge(merge(a[p[0]],a[p[1]]),a[p[2]]).n);
	while(next_permutation(p.begin(),p.end()));
	cout<<ans<<"\n";
}