#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e4+10;
int a,n,t;
ll s;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s=0;
		bool flag=true;
		for(ri i=1;i<=n;++i){
			scanf("%d",&a);
			s+=a;
			if(s<1ll*i*(i-1)/2)flag=false;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}