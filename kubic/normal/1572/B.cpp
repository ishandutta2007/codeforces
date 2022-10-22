#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,s,a[N],st[N],ans[N];
void f(int x) {ans[++ans[0]]=x;a[x]=a[x+1]=a[x+2]=a[x]^a[x+1]^a[x+2];}
bool upd(int x)
{
	if(x<1 || x>n || !a[x]) return 1;
	int ps=0;for(int i=x;i;--i) if(!a[i]) {ps=i;break;}
	if(ps) {for(int i=ps;i<n-1 && a[i+1] && a[i+2];i+=2) f(i);return 1;}
	for(int i=x;i<=n;++i) if(!a[i]) {ps=i;break;}
	if(ps) {for(int i=ps-2;i>0 && a[i];i-=2) f(i);return 1;}return 0;
}
void slv1()
{
	st[0]=0;st[++st[0]]=0;
	for(int i=1;i<=n;++i) if(a[i]) ++st[st[0]];else st[++st[0]]=0;
}
void slv()
{
	scanf("%d",&n);s=ans[0]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s^=a[i];slv1();
	if(s || st[0]<2) {puts("NO");return;}
	for(int i=1,nw=0,lst=0;i<=st[0];++i)
	{
		if(st[i])
		{
			if(lst)
			{
				for(int j=lst;j<nw;j+=2) f(j);
				if(nw-lst&1)
				{
					if(!upd(nw-2)) {puts("NO");return;}
					if(!upd(nw+2)) {puts("NO");return;}
					if(!(st[i]&1)) lst=nw+st[i];else lst=0;
				}
				else if(st[i]&1) {lst=0;if(!(upd(nw))) {puts("NO");return;}}
				else lst=nw+st[i];
			}
			else if(st[i]&1) lst=nw+st[i];
			else if(!upd(nw+1)) {puts("NO");return;}
		}nw+=st[i]+1;
	}printf("YES\n%d\n",ans[0]);
	for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);if(ans[0]) puts("");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}