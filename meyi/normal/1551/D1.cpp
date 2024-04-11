#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],k,m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		if(m&1){
			ri mx=(m-1)*n/2;
			if(k>mx){
				puts("NO");
				continue;
			}
		}
		if(n&1){
			if(k<m/2){
				puts("NO");
				continue;
			}
			k-=m/2;
			--n;
			if(!n){
				puts("YES");
				continue;
			}
		}
		ri tmp=k%n;
		if((n-tmp)&1)puts("NO");
		else puts("YES");
	}
	return 0;
}