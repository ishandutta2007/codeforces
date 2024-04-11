#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s%s",&n,s+1,t+1);
		bool c0=false,c1=false;
		ri ans=0;
		for(ri i=1;i<=n;++i){
			switch(s[i]+t[i]){
				case 96:{
					if(c1)ans+=2,c0=c1=false;
					else{
						if(c0)++ans;
						else c0=true;
					}
					break;
				}
				case 97:{
					if(c0)++ans;
					ans+=2;
					c0=c1=false;
					break;
				}
				case 98:{
					if(c0)ans+=2,c0=c1=false;
					else c1=true;
					break;
				}
			}
		}
		printf("%d\n",ans+c0);
	}
	return 0;
}