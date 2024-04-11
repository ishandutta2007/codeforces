#include <stdio.h>
#include <algorithm>

int x[100001],y[100001],z[100001];
char s[100000];

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

int main(){	
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int l,r,i,n,j,x1,y1,z1;
	scanf("%s",&s);
	scanf("%d",&n);
	x[0]=0;
	y[0]=0;
	z[0]=0;
	for(i=1;i<strlen(s)+1;i++){
		switch(s[i-1]){
		case 'x':
			x[i]=x[i-1]+1;
			y[i]=y[i-1];
			z[i]=z[i-1];
			break;
		case 'y':
			x[i]=x[i-1];
			y[i]=y[i-1]+1;
			z[i]=z[i-1];
			break;
		case 'z':
			x[i]=x[i-1];
			y[i]=y[i-1];
			z[i]=z[i-1]+1;
			break;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d%d",&l,&r);
		x1=x[r]-x[l-1];
		y1=y[r]-y[l-1];
		z1=z[r]-z[l-1];
		if(r-l<2||(abs(x1-y1)<2 && abs(y1-z1)<2 && abs(z1-x1)<2)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}