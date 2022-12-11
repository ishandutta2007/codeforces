#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int md=1000000007;
int n,m;
int a[5001];
vector<int>p[5001],q[5001],g[5001];
struct da{int s,w;};
da operator+(da u,da v){
	return u.s>v.s?u:u.s<v.s?v:(da){u.s,(u.w+v.w)%md};
}
da operator-(da u,da v){
	return u.s>v.s?u:u.s<v.s?v:(da){u.s,(u.w-v.w+md)%md};
}
da operator*(da u,da v){
	return(da){u.s+v.s,1ll*u.w*v.w%md};
}
da cc(int l,int r){
	da ans=(da){0,1};
	for(int i=1;i<=n;i++){
		int u=0,v=0;
		while(u<g[i].size()&&p[i][min((int)p[i].size()-1,g[i][u]-1)]<=l)u++;
		while(v<g[i].size()&&q[i][min((int)q[i].size()-1,g[i][v]-1)]>=r)v++;
		da o;
		if(min(u,v)>=1&&max(u,v)>=2)
			o=(da){2,1ll*min(u,v)*(max(u,v)-1)%md};
		else if(u==0&&v==0)
			o=(da){0,1};
		else o=(da){1,(u+v)%md};
		ans=ans*o;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]].push_back(i);
	}
	for(int i=n;i;i--)
		q[a[i]].push_back(i);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
		p[i].push_back(n+1);
		q[i].push_back(0);
	}
	da ans=(da){0,0};
	for(int i=0;i<=n;i++)
		ans=ans+cc(i,i+1);
	for(int i=0;i+1<=n;i++)
		ans=ans-cc(i,i+2);
	printf("%d %d\n",ans.s,ans.w);
}