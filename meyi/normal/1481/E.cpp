#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],cnt[maxn],f[maxn],l[maxn],n,r[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(!l[a[i]])l[a[i]]=i;
		r[a[i]]=i;
	}
	for(ri i=n;i;--i)f[i]=max(f[i+1],++cnt[a[i]]+(i==l[a[i]]?f[r[a[i]]+1]:0));
	printf("%d",n-f[1]);
	return 0;
}