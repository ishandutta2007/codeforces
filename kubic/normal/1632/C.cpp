#include <bits/stdc++.h>
using namespace std;
int T,a,b,ans;
void slv()
{
	scanf("%d %d",&a,&b);ans=min(b-a,(a|b)-b+1);
	if(a>=b) {printf("%d\n",a-b);return;}
	for(int i=0,t;i<=20;++i) if(!(a>>i&1) && b>>i&1)
		t=(a&(1<<20)-(1<<i))|(1<<i),ans=min(ans,t-a+(t|b)-b+1);
	for(int i=0,t;i<=20;++i) if(a>>i&1 && !(b>>i&1))
		t=(b&(1<<20)-(1<<i))|(1<<i),ans=min(ans,t-b+(a|t)-t+1);
	printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}