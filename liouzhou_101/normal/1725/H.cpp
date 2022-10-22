#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<complex>
#define ll long long
using namespace std;
int sum[3];
int a[100020];
int n;
int main(){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
		//	printf("%d %d %d\n",i,j, ((i+j) * (i+j) + i*j) % 3);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		a[i] %= 3;
		++ sum[a[i]];
	}
	if(sum[0] < n/2){
		printf("%d\n",0);
		int m = n/2 - sum[0];
		for(int i=0;i<n;++i){
			if(a[i] == 0)printf("0");
			else if(m){
				printf("0");
				--m;
			}else printf("1");
		}
		printf("\n");
	}else{
		printf("2\n");
		int m = n/2 - (n-sum[0]);
		for(int i=0;i<n;++i){
			if(a[i] != 0)printf("0");
			else if(m){
				printf("0");
				--m;
			}else printf("1");
		}
		printf("\n");		
	}
	return 0;
}