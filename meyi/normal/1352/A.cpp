#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],cnt,m,n,pow10[10],t_case;
int main(){
	scanf("%d",&t_case);
	pow10[0]=1;
	for(ri i=1;i<=5;++i)pow10[i]=pow10[i-1]*10;
	while(t_case--){
		scanf("%d",&n);
		while(n)a[++m]=n%10,n/=10,cnt+=bool(a[m]);
		printf("%d\n",cnt);
		for(ri i=m;i;--i)if(a[i])printf("%d ",a[i]*pow10[i-1]);
		puts("");
		cnt=m=0;
	}
	return 0;
}