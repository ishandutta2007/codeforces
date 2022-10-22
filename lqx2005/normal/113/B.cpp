#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=2000;
const int De=8823823;
char s[maxn+5],a[maxn+5],b[maxn+5];
int n,an,bn,p,tot=0;
ull Ca[maxn+5],pd[maxn+5],H1=0,H2=0;
ull num[maxn*maxn+5];
ull query(int l,int r)
{
	return Ca[r]-Ca[l-1]*pd[r-l+1];
}
signed main()
{
	scanf("%s",s+1);
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(s+1);
	an=strlen(a+1);
	bn=strlen(b+1);
	pd[0]=1;
	for(int i=1;i<=n;i++) pd[i]=pd[i-1]*De;
	for(int i=1;i<=n;i++) Ca[i]=(Ca[i-1]*De+1ll*s[i]);
	for(int i=1;i<=an;i++) H1=(H1*De+1ll*a[i]);
	for(int i=1;i<=bn;i++) H2=(H2*De+1ll*b[i]); 
	p=max(an,bn);
	int tot=0;
	for(int L=1;L<=n;L++)
	{
		for(int R=L+p-1;R<=n;R++)
		{
			if(query(L,L+an-1)!=H1||query(R-bn+1,R)!=H2) continue;
			num[++tot]=query(L,R);
		}
	}
	sort(num+1,num+tot+1);
	tot=unique(num+1,num+tot+1)-(num+1);
	printf("%d\n",tot);
	return 0;
	
}