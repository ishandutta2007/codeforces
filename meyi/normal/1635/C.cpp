#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct node{int x,y,z;};
ll a[maxn];
int n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		vector<node>ans;
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%lld",a+i);
		a[n+1]=2e9;
		ri pos=0;
		for(ri i=n;i;--i){
			if(a[i]>a[i+1]){
				if(!pos||pos==i+1){
					puts("-1");
					goto skip;
				}
				ans.push_back({i,i+1,pos});
				a[i]=a[i+1]-a[pos];
			}
			if(a[i]>=0&&!pos)pos=i;
		}
		printf("%d\n",(int)ans.size());
		for(node i:ans)printf("%d %d %d\n",i.x,i.y,i.z);
		skip:;
	}
	return 0;
}