#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int d=3,maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],n,pos[maxn];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),pos[a[i]]=i;
	for(ri i=1;i+2<=n;++i)
		for(ri j=i+1;j<=i+d&&j<=n;++j){
			if(2*a[i]-a[j]>0&&2*a[i]-a[j]<=n&&pos[2*a[i]-a[j]]<i)return puts("YES"),0;
			if(2*a[j]-a[i]>0&&2*a[j]-a[i]<=n&&pos[2*a[j]-a[i]]>j)return puts("YES"),0;
		}
	puts("NO");
	return 0;
}