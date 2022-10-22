#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ri cnt=0;
		for(ri i=1;i<=n;++i)cnt+=(s[i]=='0');
		if(!cnt)puts("0");
		else{
			ri tmp=0;
			for(ri i=1;i<=n;++i)
				if(s[i]=='0'){
					ri tmp=0;
					for(ri j=i;j<=n&&s[j]=='0';++j,++tmp);
					puts(cnt==tmp?"1":"2");
					break;
				}
		}
		for(ri i=1;i<=n;++i)s[i]=0;
	}
	return 0;
}