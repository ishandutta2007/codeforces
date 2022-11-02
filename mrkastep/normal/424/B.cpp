#include <stdio.h>
#include <algorithm>
#include <math.h>

int c[1000][3],x,y,k;

void put(int a){
	int b;
	if(x*x+y*y>c[a-1][0]*c[a-1][0]+c[a-1][1]*c[a-1][1] || a==0){
		c[a][0]=x;
		c[a][1]=y;
		c[a][2]=k;
	}
	else{
		c[a][0]=c[a-1][0];
		c[a][1]=c[a-1][1];
		c[a][2]=c[a-1][2];
		put(a-1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int a[1000],s,n,i;
	double r;
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&x,&y,&k);
		put(i);
	}
	for(i=0;i<n;i++){
		a[i]=c[i][0]*c[i][0]+c[i][1]*c[i][1];
	}
	i=-1;
	while(s<1000000 && i<n){
		i++;
		s=s+c[i][2];
	}
	r=sqrt((double)a[i]);
	if(i<n){
		printf("%llf",r);
	}
	else{
		printf("-1");
	}
}