#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	++deg[fr];
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int id[maxn],m,n,t[maxn];
vector<int>ans;
signed main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	for(ri i=1;i<=n;++i)id[i]=i,scanf("%d",t+i);
	for(ri p=1;p<=n;++p){
		vector<int>tmp;
		for(ri i=hd[p];i;i=e[i].nxt)tmp.push_back(t[e[i].to]);
		sort(tmp.begin(),tmp.end());
		ri mex=1;
		for(auto i:tmp){
			if(i==mex)++mex;
			else if(i>mex)break;
		}
		if(mex!=t[p])return printf("-1"),0;
	}
	sort(id+1,id+n+1,[&](const int &x,const int &y){return t[x]<t[y];});
	for(ri i=1;i<=n;++i)printf("%d ",id[i]);
	return 0;
}