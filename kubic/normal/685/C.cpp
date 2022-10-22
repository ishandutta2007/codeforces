#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int T,n;ll ps,l,r,L[4],R[4],L1[4],R1[4];struct Node {ll x,y,z;}ans,a[N];
bool chk(ll x,bool fl)
{
	Node res;for(int i=0;i<4;++i) L1[i]=-6e18,R1[i]=6e18;
	for(int i=1;i<=n;++i)
	{
		L1[0]=max(L1[0],-x+a[i].x+a[i].y+a[i].z);R1[0]=min(R1[0],x+a[i].x+a[i].y+a[i].z);
		L1[1]=max(L1[1],-x-a[i].x+a[i].y+a[i].z);R1[1]=min(R1[1],x-a[i].x+a[i].y+a[i].z);
		L1[2]=max(L1[2],-x+a[i].x-a[i].y+a[i].z);R1[2]=min(R1[2],x+a[i].x-a[i].y+a[i].z);
		L1[3]=max(L1[3],-x+a[i].x+a[i].y-a[i].z);R1[3]=min(R1[3],x+a[i].x+a[i].y-a[i].z);
	}
	for(int i=0;i<2;++i)
	{
		L[0]=L1[0]-i*3;R[0]=R1[0]-i*3;for(int j=1;j<4;++j) L[j]=L1[j]-i,R[j]=R1[j]-i;
		for(int j=0;j<4;++j) L[j]=L[j]+1>>1,R[j]>>=1;
		if(L[0]>R[0] || L[1]>R[1] || L[2]>R[2] || L[3]>R[3]) continue;
		if(L[1]+L[2]+L[3]>R[0] || R[1]+R[2]+R[3]<L[0]) continue;if(!fl) return 1;
		if(L[1]+L[2]+L[3]>=L[0]) res=(Node) {L[1],L[2],L[3]};
		else if(R[1]+L[2]+L[3]>=L[0]) res=(Node) {L[0]-L[2]-L[3],L[2],L[3]};
		else if(R[1]+R[2]+L[3]>=L[0]) res=(Node) {R[1],L[0]-R[1]-L[3],L[3]};
		else res=(Node) {R[1],R[2],L[0]-R[1]-R[2]};
		printf("%lld %lld %lld\n",res.y+res.z+i,res.x+res.z+i,res.x+res.y+i);return 1;
	}return 0;
}
void slv()
{
	scanf("%d",&n);l=0;r=3e18;
	for(int i=1;i<=n;++i) scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
	while(l<=r) {ll mid=(l+r)/2;if(chk(mid,0)) r=mid-1,ps=mid;else l=mid+1;}chk(ps,1);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}