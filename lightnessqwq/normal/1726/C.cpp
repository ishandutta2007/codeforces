#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,tot;
int stk[maxn],vis[maxn],a[maxn],L[maxn],R[maxn];
string s;
vector<int>v[maxn],w[maxn];
inline void add(int x,int y){
	w[x].push_back(y),w[y].push_back(x);
}
void get(int x){
	vis[x]=1;
	for(int i=0;i<w[x].size();i++)
		if(vis[w[x][i]]==0)
			get(w[x][i]);
}
void dfs(int x){
	int lst=-1;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		dfs(y);
		if(lst!=-1)
			add(lst,R[y]);
		lst=L[y];
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),tot=ans=0;
		cin>>s,s=" "+s;
		int top=0;
		for(int i=1;i<=n+n;i++){
			if(s[i]=='(')
				stk[++top]=i,a[i]=++tot,L[tot]=i;
			else a[i]=a[stk[top]],R[a[i]]=i,add(stk[top],i),top--,v[a[stk[top]]].push_back(a[i]);
		}
		dfs(0);
		for(int i=1;i<=n+n;i++)
			if(vis[i]==0)
				ans++,get(i);
		printf("%d\n",ans);
		for(int i=0;i<=n+n;i++)
			vis[i]=a[i]=0,v[i].clear(),w[i].clear();
	}
	return 0;
}