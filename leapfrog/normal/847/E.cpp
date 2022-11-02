#include<bits/stdc++.h>
using namespace std;
int n,L[200005],R[200005],ls[200005],rs[200005];char s[200005];
inline char chk(int x)
{
	for(int i=1;i<=n;i++) if(s[i]=='P') L[i]=R[i]=i;
	for(int i=1;i<=n;i++) if(s[i]=='*')
	{
		if(ls[i]&&min(((ls[i]-L[ls[i]])<<1)+i-ls[i],((i-ls[i])<<1)+ls[i]-L[ls[i]])<=x) {R[ls[i]]=i;continue;}
		if(rs[i]&&L[rs[i]]<i) continue;else if(!rs[i]||rs[i]-i>x) return 0;else L[rs[i]]=i;
	}
	return 1;
}
int main()
{
	scanf("%d%s",&n,s+1);int l=0,r=4e5,res;
	for(int i=1,x=0;i<=n;i++) if(s[i]=='P') x=i;else if(s[i]=='*') ls[i]=x;
	for(int i=n,x=0;i>=1;i--) if(s[i]=='P') x=i;else if(s[i]=='*') rs[i]=x;
	while(l<=r) {int md=(l+r)>>1;if(chk(md)) res=md,r=md-1;else l=md+1;}
	return !printf("%d\n",res);
}