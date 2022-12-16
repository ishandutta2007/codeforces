#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int r=(n-k)/2+1;
	for(int i=0;i<n;i++){
		printf(i%r==r-1?"1":"0");
	}
	printf("\n");
	return 0;
}