#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int n,m,q,fa[N],dep[N],nxt[N],s[N];
vector<int>e[N];
void dfs(int x,int pre){
	fa[x]=pre,dep[x]=dep[pre]+1;
	for(int y:e[x])
		if(y^pre){
			if(!dep[y])
				dfs(y,x);
			else if(dep[y]<dep[x]){
				int p=fa[x],mn=min(x,y),mx=max(x,y);
				while(p!=y)
					mn=min(mn,p),mx=max(mx,p),p=fa[p];
				nxt[mn]=min(nxt[mn],mx-1);
			}
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int x,y;m--;)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	memset(nxt,0x3f,sizeof nxt);
	for(int i=1;i<=n;i++)
		if(!dep[i])
			dfs(i,0);
	for(int i=n;i>=1;i--)
		nxt[i]=min(nxt[i],nxt[i+1]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+nxt[i]-i+1;
	for(cin>>q;q--;){
		int l,r,p;cin>>l>>r;
		p=max((int)(lower_bound(nxt+1,nxt+n+1,r)-nxt),l)-1;
		cout<<s[p]-s[l-1]+(r-p)*(r-p+1)/2<<"\n";
	}
}