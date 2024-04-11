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
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,a+1);
		ri cnt=0;
		for(ri i=1;i<=n;++i)cnt+=(a[i]==48);
		puts((cnt>1&&cnt%2==1)?"ALICE":"BOB");
	}
	return 0;
}