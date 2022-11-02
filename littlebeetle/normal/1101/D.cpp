#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=400002;
int n,i,j,k,a[N],x,y,p[N],w[N],L[N*2],dep[N],vis[N],cnt,ans;
bool f[N];
pair<int,int>E;
vector<pair<int,int> >edg[N];
vector<int>t[N];
void Prepare(){
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i,w[i]=i;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<N;j++){
			f[i*a[j]]=1;
			w[i*a[j]]=a[j];
		}
	}
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>1)
			ans=1;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		E=make_pair(x,y);
		k=gcd(a[x],a[y]);
		while(k!=1){
			if((k/w[k])%w[k])
				edg[w[k]].push_back(E);
			k/=w[k];
		}
	}
}
void dfs(int i,int fa){
	vis[i]=k;
	if(dep[i]>dep[x])x=i;
	for(int j=0;j<t[i].size();j++)
		if(t[i][j]!=fa){
			dep[t[i][j]]=dep[i]+1;
			dfs(t[i][j],i);
		}
}
int max(int x,int y){
	return x>y?x:y;
}
void work(){
	for(k=1;k<N;k++)
		if(edg[k].size()){
			cnt=0;
			for(i=0;i<edg[k].size();i++){
				x=edg[k][i].first;
				y=edg[k][i].second;
				t[x].push_back(y);
				t[y].push_back(x);
				L[++cnt]=x;
				L[++cnt]=y;
			}
			for(i=1;i<=cnt;i++)
				if(vis[i]!=k){
					dep[i]=1;
					x=i;
					dfs(i,0);
					dep[x]=1;
					dfs(x,0);
					ans=max(ans,dep[x]);
				}
			for(i=1;i<=cnt;i++)
				t[L[i]].pop_back();
		}
	printf("%d",ans);
}
int main(){
	Prepare();
	init();
	work();
}