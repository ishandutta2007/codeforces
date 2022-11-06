#include<bits/stdc++.h>
#define N 1000005
using namespace std;

int n,A,B,fst[N],nxt[N],tg[N],mn[N];
void ins(int k,int l,int r,int x,int y,int z){
	if (x<=l && r<=y){ tg[k]+=z; mn[k]+=z; return; }
	int mid=l+r>>1;
	if (x<=mid) ins(k<<1,l,mid,x,y,z);
	if (y>mid) ins(k<<1|1,mid+1,r,x,y,z);
	mn[k]=tg[k]+min(mn[k<<1],mn[k<<1|1]);
}
int main(){
	scanf("%d%d",&n,&A);
	int i,j,x;
	for (i=1; i<=n; i++){
		scanf("%d",&x);
		nxt[i]=fst[x]; fst[x]=i;
	}
	for (i=fst[A]; i; i=nxt[i]){
		ins(1,1,n,i,n,-1);
	}
	for (i=1; i<=1000000; i++) if (i!=A){
		for (j=fst[i]; j; j=nxt[j]) ins(1,1,n,j,n,1);
		if (mn[1]>=0) break;
		for (j=fst[i]; j; j=nxt[j]) ins(1,1,n,j,n,-1);
	}
	printf("%d\n",(i>1000000)?-1:i);
	return 0;
}