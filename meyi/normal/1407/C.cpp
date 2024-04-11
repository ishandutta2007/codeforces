#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e4+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int ans[maxn],n,pos;
inline int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
signed main(){
	scanf("%d",&n);
	queue<int>q;
	for(ri i=1;i<=n;++i)q.push(i);
	while(q.size()>1){
		ri x=q.front();q.pop();
		ri y=q.front();q.pop();
		ri tmp1=ask(x,y),tmp2=ask(y,x);
		if(tmp1>tmp2)ans[x]=tmp1,q.push(y);
		else ans[y]=tmp2,q.push(x);
	}
	printf("!");
	for(ri i=1;i<=n;++i)printf(" %d",ans[i]?ans[i]:n);
	fflush(stdout);
	return 0;
}