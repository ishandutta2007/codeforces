#include<bits/stdc++.h>
using namespace std;
int n,q,a[100005],tp=(int)0x3f3f3f3f3f3f3f3f;long long ans=0;
inline bool cmp(int a,int b) {return a>b;}
int main()
{
	scanf("%d",&q);
	for(int i=1,x;i<=q;i++) scanf("%d",&x),tp=min(tp,x);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);int cnt=0;
	for(int i=1;i<=n;i++) {if(cnt==tp) cnt=0,i+=2;cnt++,ans+=a[i];}
	return printf("%lld\n",ans),0;
}