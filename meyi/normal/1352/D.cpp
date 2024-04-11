#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri cnt=0,l=1,r=n,lst=0,now=0,sa=0,sb=0;
		bool flag=true;
		while(l<=r){
			if(flag){
				now+=a[l++];
				if(lst<now){
					sa+=now;
					lst=now;
					now=0;
					++cnt;
					flag^=1;
				}
			}
			else{
				now+=a[r--];
				if(lst<now){
					sb+=now;
					lst=now;
					now=0;
					++cnt;
					flag^=1;
				}
			}
		}
		printf("%d %d %d\n",cnt+(now?1:0),sa+(flag?now:0),sb+(flag?0:now));
	}
	return 0;
}