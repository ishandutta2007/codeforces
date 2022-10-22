#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a,b,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&a,&b);
		bool flag=false;
		for(ll i=1;i<=n;i*=a){
			if((n-i)%b==0){flag=true;break;}
			if(a==1)break;
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}