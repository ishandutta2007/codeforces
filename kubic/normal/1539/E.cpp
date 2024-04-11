#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,mn[2],L1[2],R1[2],a[N],L[N][2],R[N][2],pr[N][2];bool fl,nw[2],tmp[2];
int main()
{
	scanf("%d %d",&n,&m);
	mn[0]=mn[1]=n+1;nw[0]=nw[1]=1;L1[0]=L1[1]=0;R1[0]=R1[1]=m; 
	for(int i=1;i<=n;++i)
		scanf("%d %d %d %d %d",&a[i],&L[i][0],&R[i][0],&L[i][1],&R[i][1]);
	for(int i=n;i;--i)
	{
		nw[0]&=a[i]>=L[i][0] && a[i]<=R[i][0];
		nw[1]&=a[i]>=L[i][1] && a[i]<=R[i][1];
		L1[0]=max(L1[0],L[i][1]);R1[0]=min(R1[0],R[i][1]);
		L1[1]=max(L1[1],L[i][0]);R1[1]=min(R1[1],R[i][0]);
		tmp[0]=nw[0] && a[i-1]>=L1[0] && a[i-1]<=R1[0];
		tmp[1]=nw[1] && a[i-1]>=L1[1] && a[i-1]<=R1[1]; 
		if(tmp[0]) pr[i][0]=mn[1];if(tmp[1]) pr[i][1]=mn[0];
		if(tmp[0]) mn[0]=i,nw[1]=1,L1[1]=0,R1[1]=m;
		if(tmp[1]) mn[1]=i,nw[0]=1,L1[0]=0,R1[0]=m;
	}if(mn[0]>1 && mn[1]>1) {puts("No");return 0;}puts("Yes");fl=mn[0]>1;
	for(int i=1;i<=n;i=pr[i][fl],fl^=1)
		for(int j=i;j<pr[i][fl];++j) printf("%d ",fl);return 0;
}