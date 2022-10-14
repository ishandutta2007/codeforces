#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,m,x,y,cnt,deg[N],flg[N];
struct dsu{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;i++)f[i]=i;
	}
	int find(int x){
		return x^f[x]?f[x]=find(f[x]):x;
	}
	int merge(int x,int y){
		return x=find(x),y=find(y),x^y?(f[x]=y,1):0;
	}
};
dsu g;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m,g.init(n);m--;)
		cin>>x>>y,deg[x]++,deg[y]++,g.merge(x,y);
	for(int i=1;i<=n;cnt+=deg[i++]&1)
		flg[g.find(i)]|=deg[i]&1;
	int t=1;
	for(int i=1;i<=n;i++)
		t&=!deg[i]||g.find(1)==g.find(i);
	if(cnt/=2,t)cout<<cnt<<"\n",exit(0);
	for(int i=1;i<=n;i++)
		if((deg[i]||i<2)&&!flg[g.find(i)])
			cnt++,flg[g.find(i)]=1;
	cout<<cnt<<"\n";
}