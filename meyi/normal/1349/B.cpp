#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],k,n,t_case;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		bool flag=false;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),flag|=(a[i]==k),vis[i]=false;
		if(!flag){
			puts("no");
			continue;
		}
		if(n==1){
			puts("yes");
			goto skip;
		}
		for(ri i=1;i<=n;++i){
			if(i+1<=n&&min(a[i],a[i+1])>=k){
				puts("yes");
				goto skip;
			}
			if(i+2<=n&&min(a[i],a[i+2])>=k){
				puts("yes");
				goto skip;
			}
		}
		puts("no");
		skip:;
	}
	return 0;
}