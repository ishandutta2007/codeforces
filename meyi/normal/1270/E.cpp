#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case,x[maxn],y[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	while(1){
		bool f0=false,f1=false;
		for(ri i=1;i<=n;++i)
			if((x[i]+y[i])&1)f1=true;
			else f0=true;
		if(f0&&f1){
			vector<int>ans;
			for(ri i=1;i<=n;++i)
				if((x[i]+y[i])&1)
					ans.push_back(i);
			printf("%d\n",(int)ans.size());
			for(ri i:ans)printf("%d ",i);
			break;
		}
		if(f1)for(ri i=1;i<=n;++i)--x[i];
		for(ri i=1;i<=n;++i){
			ri xx=x[i],yy=y[i];
			x[i]=(xx+yy)>>1,y[i]=(xx-yy)>>1;
		}
	}
	return 0;
}