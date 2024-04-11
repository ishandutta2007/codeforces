#include<iostream>
#include<stdio.h>
using namespace std;
void c(int n,long long int k){
	if(n==0)return;
	if(k >= n-1){
		printf("(");
		c(n-1,k-(n-1));
		printf(")");
	}else{
		printf("()");
		c(n-1,k);
	}
}
int main(){
	int n;long long int k;
	cin >> n >> k;
	if(k > n*(n-1LL)/2){
		puts("Impossible");
	}else{
		c(n,k);
		puts("");
	}
	return 0;
}