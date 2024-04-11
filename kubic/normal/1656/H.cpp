#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define lll __int128
#define mid ((l+r)/2)
#define gc getchar
int T,n1,n2,q1[N],q2[N];lll a1[N],a2[N],st1[N],st2[N],d[N][N];bool vs1[N],vs2[N];
lll rd()
{
	lll res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void print(lll x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
lll gcd(lll x,lll y) {return y?gcd(y,x%y):x;}
struct SegmentTree
{
	int n;lll sg[N*4][N];
	void pu(int p)
	{
		for(int i=1;i<=n;++i)
		{lll tL=sg[p*2][i],tR=sg[p*2+1][i];sg[p][i]=tL/gcd(tL,tR)*tR;}
	}
	void build(int p,int l,int r,bool fl)
	{
		if(l==r) {for(int i=1;i<=n;++i) sg[p][i]=fl?d[i][l]:d[l][i];return;}
		build(p*2,l,mid,fl);build(p*2+1,mid+1,r,fl);pu(p);
	}
	void upd(int p,int l,int r,int x)
	{
		if(l==r) {for(int i=1;i<=n;++i) sg[p][i]=1;return;}
		if(x<=mid) upd(p*2,l,mid,x);else upd(p*2+1,mid+1,r,x);pu(p);
	}
}ST1,ST2;
void slv()
{
	n1=rd();n2=rd();ST1.n=n1;ST2.n=n2;
	for(int i=1;i<=n1;++i) a1[i]=rd();for(int i=1;i<=n2;++i) a2[i]=rd();
	for(int i1=1;i1<=n1;++i1) for(int i2=1;i2<=n2;++i2) d[i1][i2]=gcd(a1[i1],a2[i2]);
	ST1.build(1,1,n2,1);ST2.build(1,1,n1,0);q1[0]=q2[0]=2;q1[1]=q2[1]=1;
	for(int i=1;i<=n1;++i) {vs1[i]=0;if(ST1.sg[1][i]<a1[i]) vs1[q1[++q1[1]]=i]=1;}
	for(int i=1;i<=n2;++i) {vs2[i]=0;if(ST2.sg[1][i]<a2[i]) vs2[q2[++q2[1]]=i]=1;}
	while(q1[0]<=q1[1] || q2[0]<=q2[1]) if(q1[0]<=q1[1])
	{
		int t=q1[q1[0]++];ST2.upd(1,1,n1,t);
		for(int i=1;i<=n2;++i) if(!vs2[i] && ST2.sg[1][i]<a2[i]) vs2[q2[++q2[1]]=i]=1;
	}
	else
	{
		int t=q2[q2[0]++];ST1.upd(1,1,n2,t);
		for(int i=1;i<=n1;++i) if(!vs1[i] && ST1.sg[1][i]<a1[i]) vs1[q1[++q1[1]]=i]=1;
	}st1[0]=st2[0]=0;
	for(int i=1;i<=n1;++i) if(!vs1[i]) st1[++st1[0]]=a1[i];
	for(int i=1;i<=n2;++i) if(!vs2[i]) st2[++st2[0]]=a2[i];
	if(st1[0] && st2[0])
	{
		puts("Yes");print(st1[0]);putchar(' ');print(st2[0]);putchar('\n');
		for(int i=1;i<=st1[0];++i) print(st1[i]),putchar(' ');putchar('\n');
		for(int i=1;i<=st2[0];++i) print(st2[i]),putchar(' ');putchar('\n');
	}else puts("No");
}
int main() {T=rd();while(T--) slv();return 0;}