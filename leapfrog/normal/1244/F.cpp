//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,L[200005],R[200005],ct,K;char ch[200005],tmp[200005];;
int main()
{
	read(n),read(K),scanf("%s",ch+1);int wh=0;
	for(int i=1;i<=n;i++) if(ch[i%n+1]==ch[i]) {wh=i;break;}
	if(!wh) {for(int i=1;i<=n;i++) putchar(K&1?ch[i]^21:ch[i]);return putchar('\n'),0;}
	for(int i=1;i<=n;i++) tmp[(i+n-wh)%n+1]=ch[i];
	ch[n+1]=tmp[1];for(int i=1;i<=n;i++) ch[i]=tmp[i];
	//for(int i=1;i<=n;i++) printf("%c",ch[i]);putchar('\n');
	for(int i=1,ls=1;i<=n;i++) if(ch[i+1]!=ch[i]) (ls^i?(L[++ct]=ls,R[ct]=i):0),ls=i+1;
	ch[1]!=ch[n]?L[++ct]=n+1:0;for(int i=1;i<ct;i++)
	{
		int ds=L[i+1]-R[i]-1;if(!ds) continue;
		//printf("%d %d\n",R[i],L[i+1]);
		if(K+K>=ds)
		{
			if(ds&1) {for(int j=R[i]+1;j<L[i+1];j++) ch[j]=ch[R[i]];continue;}
			for(int j=R[i]+1;j<L[i+1];j++) if(j<=R[i]+(ds>>1)) ch[j]=ch[R[i]];else ch[j]=ch[L[i+1]];
		}
		else
		{
			for(int j=R[i]+1;j<=R[i]+K;j++) ch[j]=ch[R[i]];
			for(int j=L[i+1]-K;j<L[i+1];j++) ch[j]=ch[L[i+1]];
			for(int j=R[i]+K+1;j<L[i+1]-K;j++) ch[j]=ch[j-1]^21;
		}
	}
	//for(int i=1;i<=n;i++) printf("%c",ch[i]);putchar('\n');
	for(int i=1;i<=n;i++) tmp[(i+wh-2)%n+1]=ch[i];
	for(int i=1;i<=n;i++) printf("%c",tmp[i]);
	return putchar('\n'),0;
}