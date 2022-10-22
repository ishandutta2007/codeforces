#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxk=8,maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int f[2][1<<maxk],id[maxn],k,m,n;
bool vis[maxk];
inline int getid(){
	for(ri i=0;i<k;++i)
		if(!vis[i]){
			vis[i]=true;
			return i;
		}
	exit(0);
}
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>evt;
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1,l,r;i<=n;++i){
		scanf("%d%d",&l,&r);
		evt.emplace_back(l,i);
		evt.emplace_back(r+1,-i);
	}
	sort(evt.begin(),evt.end());
	ri all=(1<<k)-1,cur=0,lst=0,now=1;
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	for(auto i:evt){
		ri pre=now^1;
		if(i.se>0){
			id[i.se]=getid();
			for(ri j=0;j<=all;++j)
				if((cur&j)==j){
					ckmax(f[now][j|(1<<id[i.se])],f[pre][j]+(i.fi-1-lst)*__builtin_parity(j)+(__builtin_parity(j)^1));
					ckmax(f[now][j],f[pre][j]+(i.fi-lst)*__builtin_parity(j));
				}
			cur|=(1<<id[i.se]);
		}
		else{
			i.se=-i.se;
			cur^=(1<<id[i.se]);
			for(ri j=0;j<=all;++j)
				if((cur&j)==j){
					ckmax(f[now][j],f[pre][j|(1<<id[i.se])]+(i.fi-1-lst)*(__builtin_parity(j)^1)+__builtin_parity(j));
					ckmax(f[now][j],f[pre][j]+(i.fi-lst)*__builtin_parity(j));
				}
			vis[id[i.se]]=false;
		}
		lst=i.fi,now^=1;
	}
	printf("%d",f[now^1][0]);
	return 0;
}