#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
inline int ask(int x,int y){
	ri ret1=0,ret2=0;
	printf("and %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&ret1);
	printf("or %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&ret2);
	return ret1+ret2;
}
int a[maxn],cnt,k,m,n,t_case;
int main(){
	scanf("%d%d",&n,&k);
	ri a12=ask(1,2),a13=ask(1,3),a23=ask(2,3);
	a[1]=(a12+a13-a23)/2;
	a[2]=a12-a[1];
	a[3]=a13-a[1];
	for(ri i=4;i<=n;++i)a[i]=ask(1,i)-a[1];
	sort(a+1,a+n+1);
	printf("finish %d",a[k]);
	fflush(stdout);
	return 0;
}