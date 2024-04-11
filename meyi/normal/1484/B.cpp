#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],c,m,n,t_case;
inline bool dc(){
	for(ri i=3;i<=n;++i)
		if(a[i]-a[i-1]!=a[2]-a[1])
			return false;
	return true;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		m=c=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		if(dc()){puts("0");continue;}
		for(ri i=2;i<=n;++i)
			if(a[i]>=a[i-1]){
				c=a[i]-a[i-1];
				break;
			}
		for(ri i=2;i<=n;++i)
			if(a[i]<a[i-1]){
				m=a[i-1]+c-a[i];
				break;
			}
		bool flag=false;
		for(ri i=2;i<=n;++i){
			if(a[i]>=a[i-1]&&a[i]!=a[i-1]+c){flag=true;break;}
			if(a[i]<a[i-1]&&a[i]+m!=a[i-1]+c){flag=true;break;}
			if(m<=a[i]){flag=true;break;};
		}
		if(flag||m<=a[1])puts("-1");
		else printf("%d %d\n",m,c);
	}
	return 0;
}