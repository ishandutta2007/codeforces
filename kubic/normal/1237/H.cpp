#include <bits/stdc++.h>
using namespace std;
#define N 4005
int T,n,ps1,ps2,cnt1[4],cnt2[4],b1[N],b2[N],ans[N];char a1[N],a2[N];
void f1(int x) {if(!x) return;reverse(a1+1,a1+x*2+1);ans[++ans[0]]=x;}
void f2(int x) {if(!x) return;reverse(a2+1,a2+x*2+1);}
void slv()
{
	scanf("%s %s",a1+1,a2+1);n=strlen(a1+1)/2;ps1=ps2=ans[0]=0;
	cnt1[0]=cnt1[1]=cnt1[2]=cnt1[3]=cnt2[0]=cnt2[1]=cnt2[2]=cnt2[3]=0;
	for(int i=1;i<=n;++i)
	{
		b1[i]=(a1[i*2-1]-'0')*2+a1[i*2]-'0';++cnt1[b1[i]];
		b2[i]=(a2[i*2-1]-'0')*2+a2[i*2]-'0';++cnt2[b2[i]];
	}if(cnt1[0]!=cnt2[0] || cnt1[3]!=cnt2[3]) {puts("-1");return;}
	for(int i=1,w1=0,w2=0,t1,t2;i<=n;++i)
	{
		if(b1[i]==1) ++w1;if(b1[i]==2) --w1;
		t1=cnt1[1]-cnt1[2]-w1*2;if(!t1 || t1==1) ps1=i;
		if(b2[i]==1) ++w2;if(b2[i]==2) --w2;
		t2=cnt2[1]-cnt2[2]-w2*2;if(!t2 || t2==1) ps2=i;
	}f1(ps1);f2(ps2);
	for(int i=1;i<=n;++i) for(int j=i;j<=n;++j)
		if(a1[j*2-1]==a2[i*2-1] && a1[j*2]==a2[i*2])
		{f1(j-1);if(i<n) f1(j);break;}
	if(ps2) ans[++ans[0]]=ps2;printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]*2);puts("");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}