#include<bits/stdc++.h>
#define N 100100
using namespace std;
int n,k;
int a[N];
int main(){
	scanf("%d%d",&n,&k);
	int ma=-1008610086,mi=1008610086;
	for(int i=0;i<n;i++) scanf("%d",&a[i]),mi=min(mi,a[i]),ma=max(ma,a[i]);
	if(k>=3){
		printf("%d\n",ma);
	}
	else if(k>=2){
		printf("%d\n",max(a[0],a[n-1]));
	}
	else{
		printf("%d\n",mi);
	}
	return 0;
}