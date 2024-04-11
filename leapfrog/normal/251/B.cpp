#include<bits/stdc++.h>
using namespace std;
int n,k,q[105],s[105],a[105],b[105],w1,w2;
inline int check() {for(int i=1;i<=n;i++) if(s[i]!=b[i]) return 0;return 1;}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",q+i);
	for(int i=1;i<=n;i++) scanf("%d",s+i),b[i]=i;
	for(w1=0;w1<=k;)
	{
		if(check()) break;
		for(int i=1;i<=n;i++) a[i]=b[q[i]];
		++w1,memcpy(b,a,sizeof(a));
	}
	for(int i=1;i<=n;i++) b[i]=i;
	for(w2=0;w2<=k;)
	{
		if(check()) break;
		for(int i=1;i<=n;i++) a[q[i]]=b[i];
		++w2,memcpy(b,a,sizeof(a));
	}
	if((!w1||!w2)||(w1==1&&w2==1&&k>1)) puts("NO");
	else if((w1<=k&&(k+w1)%2==0)||(w2<=k&&(k+w2)%2==0)) puts("YES");
	else puts("NO");
	return 0;
}