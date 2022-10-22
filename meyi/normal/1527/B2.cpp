#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
char a[maxn];
inline bool check(){
	for(ri i=1;(i<<1)<=n;++i)
		if(a[i]!=a[n-i+1])
			return false;
	return true;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,a+1);
		ri cnt=0;
		for(ri i=1;i<=n;++i)cnt+=(a[i]==48);
		if(check()){puts((cnt>1&&cnt%2==1)?"ALICE":"BOB");continue;}
		if((n&1)&&a[(n+1)>>1]==48&&cnt==2)puts("DRAW");
		else puts("ALICE");
	}
	return 0;
}