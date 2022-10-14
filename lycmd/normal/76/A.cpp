#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=50010,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,s,g,ans=INF,f[N];
struct edge{
	int x,y,g,s;
	int operator<(const edge&rhs)const{
		return g<rhs.g;
	}
};
vector<edge>e,t,k;
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,1):0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>g>>s;
	while(m--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		e.push_back({a,b,c,d});
	}
	sort(e.begin(),e.end());
	for(edge i:e){
		t.push_back(i);
		sort(t.begin(),t.end(),[&](edge x,edge y){
			return x.s<y.s;
		});
		for(int j=1;j<=n;j++)
			f[j]=j;
		k=t,t.clear();
		int mx=0;
		for(auto j:k)
			if(merge(j.x,j.y))
				mx=max(mx,j.s),t.push_back(j);
		if(t.size()==n-1)
			ans=min(ans,g*i.g+s*mx);
	}
	cout<<(ans<INF?ans:-1)<<"\n";
}