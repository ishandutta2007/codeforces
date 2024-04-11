#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=4e5+10;
int n,a[N],b[N],sta[N],id[N];
int ind[N],outd[N];
vector<int> g[N];
set<int> s;
void WA(){puts("-1");exit(0);}
int vis[N],sz,c,col[N];
void dfs(int u,int cur){
	vis[u]=1,sz++,c+=cur==sta[u],col[u]=cur;
	for(int v:g[u])if(!vis[v])dfs(v,cur^1);else if(col[u]==col[v])WA();
}
bool ED;
signed main(){
	n=read();
	For(i,1,n){
		a[i]=read(),b[i]=read();
		if(a[i]>b[i])swap(a[i],b[i]),sta[a[i]]=1;
		id[a[i]]=id[b[i]]=i;
		if(!((a[i]<=n)^(b[i]<=n)))WA();
	}For(i,1,n){
		int j=b[id[i]];
		//(i,j)
		if(s.size()&&*s.begin()<j){
			auto it=s.lower_bound(j);
			do{
				int k=a[id[*--it]];
				//add(k,i)
//				printf("add (%d,%d)\n",k,i);
				if(ind[k]||outd[i])WA();
				g[k].push_back(i),g[i].push_back(k);
				outd[k]=ind[i]=1;
			}while(it!=s.begin());
			s.erase(++s.begin(),s.lower_bound(j));
		}s.insert(j);
	}s.clear();
	Rof(i,n,1){
		int j=b[id[i]];
		if(s.size()&&*s.rbegin()>j){
			for(auto it=s.lower_bound(j);it!=s.end();it++){
				int k=a[id[*it]];
				//add(i,k)
//				printf("add (%d,%d)\n",i,k);
				if(ind[i]||outd[k])WA();
				g[i].push_back(k),g[k].push_back(i);
				outd[i]=ind[k]=1;
			}s.erase(s.lower_bound(j),--s.end());
		}s.insert(j);
	}int ans=0;For(i,1,n)if(!vis[i])sz=0,c=0,dfs(i,0),ans+=min(c,sz-c);
	cout<<ans<<endl;
//	For(i,1,n)printf("%d ",sta[i]);puts("");
	return 0;
}