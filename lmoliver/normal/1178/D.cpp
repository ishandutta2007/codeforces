#include<bits/stdc++.h>
using namespace std;
bool isP(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int m=n;m<=n+n/2;m++){
		if(isP(m)){
			printf("%d\n",m);
			for(int i=1;i<=n;i++){
				printf("%d %d\n",i,i%n+1);
			}
			for(int i=n+1;i<=m;i++){
				int j=i-n;
				printf("%d %d\n",j,j+n/2);
			}
			exit(0);
		}
	}
	assert(false);
	return 0;
}