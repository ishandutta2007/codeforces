//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int N=100005;int n,m,l[N][2],r[N][2],c[N],nx[N][2];
int main()
{
	read(n),read(m);int wh[2]={n+1,n+1};for(int i=1;i<=n;i++)
		read(c[i]),read(l[i][0]),read(r[i][0]),read(l[i][1]),read(r[i][1]);
	int nw[2]={1,1},ck[2]={0,0},L[2]={0,0},R[2]={m,m};for(int i=n;i;i--)
	{
		nw[0]&=l[i][0]<=c[i]&&c[i]<=r[i][0],nw[1]&=l[i][1]<=c[i]&&c[i]<=r[i][1];
		L[0]=max(L[0],l[i][1]),R[0]=min(R[0],r[i][1]),L[1]=max(L[1],l[i][0]),R[1]=min(R[1],r[i][0]);
		ck[0]=nw[0]&&(L[0]<=c[i-1]&&c[i-1]<=R[0]),ck[1]=nw[1]&&(L[1]<=c[i-1]&&c[i-1]<=R[1]);
		(ck[0]?nx[i][0]=wh[0]:0),(ck[1]?nx[i][1]=wh[1]:0);
		if(ck[0]) nw[1]=1,wh[1]=i,L[1]=0,R[1]=m;
		if(ck[1]) nw[0]=1,wh[0]=i,L[0]=0,R[0]=m;
	}
	if(wh[0]>1&&wh[1]>1) return puts("No"),0;else puts("Yes");
	for(int i=1,p=wh[1]>1;i<=n;i=nx[i][p],p^=1) for(int j=i;j<nx[i][p];j++) printf("%c ",'0'|p);
	return putchar('\n'),0;
}