#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[MAXN];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ll ans=0;
		for(int i=1,j=1,k=0,l=0; i<=n; i++){
			if(s[i]=='?'){
			}else{
				if(!l){
					l=1;
				}else if(abs(s[i]-s[k])!=(i-k&1)) j=k+1;
				k=i;
			}
			ans+=i-j+1;
			//printf("%d j %d\n",i,j);
		}
		printf("%lld\n",ans);
	}
	return 0;
}