#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],m,n,s,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool ans=false;
		m=s=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			ans^=(a[i]&1);
			s+=a[i];
			m=max(m,a[i]);
		}
		if(m>s-m)puts("T");
		else puts(ans?"T":"HL");
	}
	return 0;
}