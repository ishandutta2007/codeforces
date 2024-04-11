#include <stdio.h> 
#include <algorithm> 
#include <vector>
#include <math.h>

int n,a[101],s[101];

void solve(int n){
	int i,j,m;
	s[0]=0;
	for(i=1;i<n+1;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	m=-1000;
	for(i=1;i<n+1;i++){
		for(j=i;j<n+1;j++){
			if(j-i+1-(s[j]-s[i-1])*2>m) m=j-i+1-(s[j]-s[i-1])*2;
		}
	}
	printf("%d",s[n]+m);
}

int main(){
#pragma comment (linker,"/STACK:16777216")
#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
#endif
	while(scanf("%d",&n)!=EOF) solve(n);
}