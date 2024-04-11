#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll ans,sum;
int f[maxn],n;
char s[maxn];
int main(){
	scanf("%d%s",&n,s+1);
	for(ri i=1,j=0,k=0;i<=n;++i){
		if(s[i]^48){
			f[i]=f[i-1]+1;
			sum+=i-j;
			while(j&&f[i]>k){
				sum+=f[i]-k;
				f[j]=f[i];
				ckmax(k,f[--j]);
			}
		}
		else j=i,k=0,reverse(f+i-f[i-1],f+i);
		ans+=sum;
	}
	printf("%lld",ans);
	return 0;
}