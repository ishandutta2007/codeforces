#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[3][maxn];
bool vis[3][maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
queue<pii>q;
inline void insert(pii p){
	if(vis[p.fi][p.se])return;
	vis[p.fi][p.se]=true;
	q.push(p);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s%s",&m,s[1]+1,s[2]+1);
		for(ri i=1;i<=m;++i)vis[1][i]=vis[2][i]=false;
		bool flag=false;
		while(q.size())q.pop();
		q.push({1,1});
		while(q.size()){
			pii p=q.front();q.pop();
			if(p.fi==2&&p.se==m){
				flag=true;
				break;
			}
			if(p.fi-1==1&&p.se<m&&s[p.fi-1][p.se+1]=='0')insert({p.fi-1,p.se+1});
			if(p.se<m&&s[p.fi][p.se+1]=='0')insert({p.fi,p.se+1});
			if(p.fi+1==2&&p.se<m&&s[p.fi+1][p.se+1]=='0')insert({p.fi+1,p.se+1});
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}