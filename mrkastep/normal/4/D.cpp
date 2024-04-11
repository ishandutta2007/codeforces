#include <stdio.h>
#include <algorithm>

int a[5001][5],o,t;

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

void put(int p,int w1,int h1,int x){
	if(a[p-1][0]+a[p-1][1]>=w1+h1||p==0){
		a[p][0]=w1;
		a[p][1]=h1;
		a[p][3]=x;
		o=p;
	}
	else{
		a[p][0]=a[p-1][0];
		a[p][1]=a[p-1][1];
		a[p][3]=a[p-1][3];
		put(p-1,w1,h1,x);
	}
}

int chk(int b){
	if(a[b][0]>a[t][0] && a[b][1]>a[t][1]){
		return 1;
	}
	return 0;
}

int main(){	
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int i,j,n,w,h,w1,h1,max,r,res[5001];
	scanf("%d%d%d",&n,&w,&h);
	for(i=0;i<n;i++){
		scanf("%d%d",&w1,&h1);
		put(i,w1,h1,i+1);
	}
	put(n,w,h,0);
	t=0;
	for(i=0;i<n+1;i++){
		a[i][2]=1;
	}
	for(i=0;i<o+1;i++){
		max=0;
		r=-1;
		for(j=0;j<i;j++){
			if(a[j][2]*chk(j)>max){
				max=a[j][2];
				r=j;
			}
		}
		a[i][2]=max+1;
		a[i][4]=r;
		t++;
	}
	#ifndef ONLINE_JUDGE
	for(i=0;i<n+1;i++){
		printf("%d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][4]);
	}
	#endif
	i=o;
	res[0]=a[o][2]-1;
	j=1;
	while(res[0]>0){
		res[j]=a[a[i][4]][3];
		i=a[i][4];
		j++;
		res[0]--;
	}
	printf("%d\n",a[o][2]-1);
	for(i=1;i<j;i++){
		printf("%d ",res[i]);
	}
}