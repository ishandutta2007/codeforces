#include<bits/stdc++.h>
#define FAIL(x) if(x)cout<<"-1\n",exit(0);
using namespace std;
int const N=100010;
int n,m,c1,c2,f[N],flg[N],ans[N];
char c;
vector<array<int,3> >e[2];
void init(int n){
	for(int i=1;i<=n;i++)
		f[i]=i;
}
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,init(n);
	FAIL(~n&1)
	for(int i=1,a,b;i<=m;i++)
		cin>>a>>b>>c,e[c>>1&1].push_back({a,b,i});
	for(auto&i:e[0])
		c1+=merge(i[0],i[1]);
	FAIL(c1<n/2)
	for(auto&i:e[1])
		c2+=flg[i[2]]=merge(i[0],i[1]);
	FAIL(c1+c2<n-1)
	init(n);
	for(auto&i:e[1])
		if(flg[i[2]])
			merge(i[0],i[1]),ans[i[2]]=1;
	for(auto&i:e[1])
		if(c2<n/2&&merge(i[0],i[1]))
			c2++,ans[i[2]]=1;
	FAIL(c2<n/2)
	for(auto&i:e[0])
		ans[i[2]]=merge(i[0],i[1]);
	cout<<n-1<<"\n";
	for(int i=1;i<=m;i++)
		if(ans[i])
			cout<<i<<" ";
	cout<<"\n";
}