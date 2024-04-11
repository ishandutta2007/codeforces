#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,MOD=1000000007;
int n,m,f[N];
set<int>s;
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx^fy)f[fx]=fy;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n+n;i++)
		f[i]=i;
	for(int x,y,v;m--;)
		if(cin>>x>>y>>v,(!v&&find(x)==find(y))||(v&&abs(find(x)-find(y))==n))
			cout<<"0\n",exit(0);
		else if(v)
			merge(x,y),merge(x+n,y+n);
		else
			merge(x+n,y),merge(x,y+n);
	for(int i=1;i<=n;i++)
		s.insert(find(i)),s.insert(find(i)+(find(i)>n?-n:n));
	cout<<qpow(2,s.size()/2-1)<<"\n";
}