#include <bits/stdc++.h>
using namespace std;
#define N 200005
const int lim=2e4;
int T,n;bool fl,vs1[N],vs2[N];
void slv()
{
	scanf("%d",&n);fl=0;for(int i=0;i<=lim;++i) vs1[i]=vs2[i]=0;
	for(int i=1,len,t,hs[3];i<=n;++i)
	{
		char a[15];scanf("%s",a);len=strlen(a);
		if(len==1) fl=1;
		if(len==2 && a[0]==a[1]) fl=1;
		if(len==3 && a[0]==a[2]) fl=1;
		reverse(a,a+len);t=0;
		for(int j=0;j<len;++j) t=t*27+a[j]-'a'+1,hs[j]=t;
		if(len>1 && vs1[hs[1]]) fl=1;
		if(len==2 && vs2[hs[1]]) fl=1;
		if(len==3 && vs2[hs[2]]) fl=1;
		reverse(a,a+len);t=0;
		for(int j=0;j<len;++j)
		{
			t=t*27+a[j]-'a'+1;
			if(len>2) vs2[t]=1;else vs1[t]=1;
		}
	}puts(fl?"YES":"NO");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}