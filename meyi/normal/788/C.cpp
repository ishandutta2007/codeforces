#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int d=1e3,maxm=1e3+10,maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],dis[maxm+d],m,n;
queue<int>q;
set<int>s;
signed main(){
	for(ri i=-1000+d;i<=1000+d;++i)dis[i]=-1;
	scanf("%d%d",&m,&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		a[i]-=m;
		if(dis[a[i]+d]==-1){
			dis[a[i]+d]=1;
			q.push(a[i]+d);
			s.insert(a[i]);
		}
	}
	while(q.size()){
		ri p=q.front();q.pop();
		for(ri i:s)
			if(p+i>=-1000+d&&p+i<=1000+d&&dis[p+i]==-1)
				dis[p+i]=dis[p]+1,q.push(p+i);
	}
	printf("%d",dis[0+d]);
	return 0;
}