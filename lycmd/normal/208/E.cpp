#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=18;
int n,q,cur,dep[N],ldfn[N],rdfn[N],sz[N],fa[N][B];
vector<int>e[N],sonl[N],sonr[N];
void dfs(int x){
	sonl[dep[x]].push_back(ldfn[x]=++cur);
	for(int i=1;i<B;i++)
		if(!(fa[x][i]=fa[fa[x][i-1]][i-1]))
			break; 
	for(int y:e[x])
		fa[y][0]=x,dep[y]=dep[x]+1,dfs(y);
	sonr[dep[x]].push_back(rdfn[x]=++cur);
}
int jump(int x,int k){
	for(int i=0;i<B;i++)
		x=k>>i&1?fa[x][i]:x;
	return x;
}
int ask(int x,int k){
	return(lower_bound(sonr[k].begin(),sonr[k].end(),rdfn[x])-sonr[k].begin())-
		(lower_bound(sonl[k].begin(),sonl[k].end(),ldfn[x])-sonl[k].begin())-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n,n++;
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		e[x+1].push_back(i);
	}
	dfs(1);
	for(cin>>q;q--;){
		int x,k;cin>>x>>k,x++;
		cout<<(dep[x]<=k?0:ask(jump(x,k),dep[x]))<<" ";
	}
}