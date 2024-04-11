#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		ri ans=0;
		for(ri i=1;i<n;++i){
			scanf("%d",&a);
			if(a<=m)m-=a,ans+=a,a=0;
			else ans+=m,a-=m,m=0;
			printf("%d ",a);
		}
		scanf("%d",&a);
		printf("%d\n",a+ans);
	}
	return 0;
}