#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=110;
int f[maxn][2],l[maxn],m,n,r[maxn],t[maxn],t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		memset(f,-0x3f,sizeof f);
		f[0][0]=f[0][1]=m;
		t[0]=0;
		bool flag=false;
		for(ri i=1;i<=n;++i){
			scanf("%d%d%d",t+i,l+i,r+i);
			ri d=t[i]-t[i-1];
			if(f[i-1][1]+d<l[i]||f[i-1][0]-d>r[i])flag=true;
			f[i][0]=max(f[i-1][0]-d,l[i]);
			f[i][1]=min(f[i-1][1]+d,r[i]);
		}
		puts(flag?"NO":"YES");
	}
	return 0;
}