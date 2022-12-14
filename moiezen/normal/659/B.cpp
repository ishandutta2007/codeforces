#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
#define M 10005
int l[M][5];
int n,m,i,j,k,ans;
int str[N][11];
int ind[N],rat[N];
bool cmp(int x,int y){
	return rat[x]>rat[y];
}
int update(int id,int x){
	l[x][3]=id;
	std::sort(l[x],l[x]+4,cmp);
}
int main(){
	scanf("%d%d",&n,&m);rat[0]=-233;
	rpt(i,1,n){
		scanf("%s%d%d",str[i],&ind[i],&rat[i]);
		update(i,ind[i]);
	}
	rpt(i,1,m) if(rat[l[i][1]]==rat[l[i][2]]) printf("?\n");
	else printf("%s %s\n",str[l[i][0]],str[l[i][1]]);
}