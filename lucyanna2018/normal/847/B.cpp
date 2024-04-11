#include<stdio.h>
#include<algorithm>
using namespace std;
int n,val[222222 * 4],c[222222];
void build(int i,int s,int e){
	if(s==e){
		val[i] = c[s];
		return;
	}
	int m=(s+e)/2;
	build(i*2,s,m);
	build(i*2+1,m+1,e);
	val[i] = max(val[i*2],val[i*2+1]);
}
void upd(int i,int s,int e,int x){
	if(s==e){
		val[i] = -1;
		return;
	}
	int m=(s+e)/2;
	if(x<=m)upd(i*2,s,m,x);else
		upd(i*2+1,m+1,e,x);
	val[i] = max(val[i*2],val[i*2+1]);
}
int query_rig(int i,int s,int e,int x,int z){
	if(val[i] <= z)return n;
	if(s==e)return s;
	if(e < x)return n;
	if(s >= x){
		int m = (s+e)/2;
		int w = query_rig(i*2, s, m, x, z);
		return w == n ? query_rig(i*2+1,m+1,e,x,z) : w;
	}
	int m = (s+e)/2;
	if(m < x)return query_rig(i*2+1,m+1,e,x,z);else{
		int w = query_rig(i*2,s,m,x,z);
		return w == n ? query_rig(i*2+1,m+1,e,x,z) : w;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&c[i]);
	build(1,0,n-1);
	while(val[1] != -1){
		int pos = query_rig(1, 0, n-1, 0, -1);
		printf("%d",c[pos]);
		upd(1,0,n-1,pos);
		while(true){
			pos = query_rig(1,0,n-1,pos+1,c[pos]);
			if(pos==n)break;
			printf(" %d",c[pos]);
			upd(1,0,n-1,pos);
		}
		puts("");
	}
	return 0;
}