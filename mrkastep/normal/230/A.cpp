#include <stdio.h>
#include <algorithm>

int a[1000][2],x,y;

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

void put(int p){
	if(x>=a[p-1][0]||p==0){
		a[p][0]=x;
		a[p][1]=y;
	}
	else{
		a[p][0]=a[p-1][0];
		a[p][1]=a[p-1][1];
		put(p-1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int s,n,i;
	bool t;
	scanf("%d%d",&s,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		put(i);
	}
	t=true;
	i=0;
	while(t && i<n){
		if(s>a[i][0]){
			s=s+a[i][1];
			i++;
		}
		else t=false;
	}
	if(t) printf("YES");
	else printf("NO");
}