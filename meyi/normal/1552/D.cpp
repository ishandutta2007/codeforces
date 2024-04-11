#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
map<int,bool>ft;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=0;i<n;++i)scanf("%d",a+i);
		ri all=1<<n;
		ft.clear();
		bool flag=false;
		for(ri i=0;i<all;++i){
			ri sum=0;
			for(ri j=0;j<n;++j)
				if(i&(1<<j))
					sum+=a[j];
			if(ft[sum]){
				flag=true;
				break;
			}
			ft[sum]=true;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}