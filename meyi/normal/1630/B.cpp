#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
int a[maxn],b[maxn],k,l,n,r,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
		sort(b+1,b+n+1);
		l=0,r=n+1;
		for(ri i=1,j=1;i<=n;++i){
			while(j<n&&2*(j-i+1)-n<k)++j;
			if(2*(j-i+1)-n>=k&&b[j]-b[i]<r-l)l=b[i],r=b[j];
		}
		printf("%d %d\n",l,r);
		for(ri i=1;i<=n;++i)a[i]=a[i-1]+(l<=a[i]&&a[i]<=r?1:-1);
		ri lst=0;
		for(ri i=1,j=1;i<=n;++i){
			if(j==k)break;
			if(a[i]==j)printf("%d %d\n",lst+1,i),++j,lst=i;
		}
		printf("%d %d\n",lst+1,n);
	}
	return 0;
}