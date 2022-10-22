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
		for(ri i=1;i<=n;++i)scanf("%d",a+i),a[i]^=a[i-1];
		bool flag=false;
		for(ri i=1;i<n;++i)
			if((a[n]^a[i])==a[i]){
				flag=true;
				break;
			}
		for(ri i=1;i<n;++i)
			for(ri j=i+1;j<n;++j)
				if((a[n]^a[j])==(a[j]^a[i])&&(a[j]^a[i])==a[i]){
					flag=true;
					break;
				}
		puts(flag?"YES":"NO");
	}
	return 0;
}