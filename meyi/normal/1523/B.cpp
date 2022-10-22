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
		printf("%d\n",3*n);
		for(ri i=1;i<=n;i+=2)
			for(ri j=0;j<3;++j){
				printf("1 %d %d\n2 %d %d\n",i,i+1,i,i+1);
				a[i]+=a[i+1];
				a[i+1]-=a[i];
			}
	}
	return 0;
}