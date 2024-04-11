#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=200005,maxk=21;
int n,m,q;
int a[maxn],lg[maxn],st[maxn][maxk];
int query(int l,int r){
	int k=lg[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	lg[0]=-1;
	for(int i=1;i<maxn;i++)
		lg[i]=lg[i>>1]+1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),st[i][0]=a[i];
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=m;j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	scanf("%d",&q);
	for(int i=1,ax,ay,bx,by,k;i<=q;i++){
		scanf("%d%d%d%d%d",&ax,&ay,&bx,&by,&k);
		if(ay>by)
			swap(ax,bx),swap(ay,by);
		if((by-ay)%k){
			puts("NO");
			continue;
		}
		ax+=((n-ax)/k)*k,bx+=((n-bx)/k)*k;
		if(ax==bx&&query(ay,by)<ax)
			puts("YES");
		else puts("NO");
	}
	return 0;
}