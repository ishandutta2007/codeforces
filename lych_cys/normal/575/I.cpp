#include<bits/stdc++.h>
#define N 5005
#define M 75
using namespace std;

int n,m,cnt,pos[N],lf[N],rg[N];
struct bit{
	int a[N],b[M];
	void ins(int x,int t){
		a[x]+=t; b[pos[x]]+=t;
	}
	int getsum(int x){
		if (x<0) return 0; if (x>n) x=n;
		int t=0,i;
		for (i=1; i<pos[x]; i++) t+=b[i];
		for (i=lf[pos[x]]; i<=x; i++) t+=a[i];
		return t;
	}
}blk[M][3],c[N];
int qry(int x,int y){
	int z=pos[x];
	return blk[z][0].getsum(y+x-lf[z])+blk[z][1].getsum(y-(x-lf[z]))+blk[z][2].getsum(y)+c[x].getsum(y);
}
void ins(int l,int r,int x,int y,int u,int v,bool w){
	int i;
	if (pos[l]==pos[r]){
		for (i=l; i<=r; i++){
			c[i].ins(x,y); c[i].ins((w)?u+i-l:u-(i-l),v);
		}
		return;
	}
	for (i=pos[l]+1; i<pos[r]; i++){
		blk[i][2].ins(x,y); blk[i][w].ins((w)?u+lf[i]-l:u-(lf[i]-l),v);
	}
	for (i=l; i<=rg[pos[l]]; i++){
		c[i].ins(x,y); c[i].ins((w)?u+i-l:u-(i-l),v);
	}
	for (i=lf[pos[r]]; i<=r; i++){
		c[i].ins(x,y); c[i].ins((w)?u+i-l:u-(i-l),v);
	}
}
int main(){
	scanf("%d%d",&n,&m); n++;
	int op,k,x,y,z,i,j;
	cnt=(int)sqrt(n);
	for (i=1; i<=cnt; i++){
		lf[i]=rg[i-1]+1; rg[i]=rg[i-1]+cnt;
	}
	rg[cnt]=n;
	for (i=1; i<=cnt; i++)
		for (j=lf[i]; j<=rg[i]; j++) pos[j]=i;
	while (m--){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d%d%d",&k,&x,&y,&z);
			if (k==1) ins(x,x+z,y,1,y+z+1,-1,0); else
			if (k==2) ins(x,x+z,y+1,-1,y-z,1,1); else
			if (k==3) ins(x-z,x,y,1,y+1,-1,1); else
			if (k==4) ins(x-z,x,y+1,-1,y,1,0);
		} else{
			scanf("%d%d",&x,&y);
			printf("%d\n",qry(x,y));
		}
	}
	return 0;
}