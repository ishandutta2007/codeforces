#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		if(a[1]<0){
			puts("NO");
			continue;
		}
		ri g=a[1];
		for(ri i=2;i<=n;++i)g=gcd(g,a[i]);
		printf("YES\n%d\n",a[n]/g+1);
		for(ri i=0;i<=a[n];i+=g)printf("%d ",i);
		printf("\n");
	}
	return 0;
}