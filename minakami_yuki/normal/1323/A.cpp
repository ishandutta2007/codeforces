#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000;
int n;
int a[N];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		bool flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i){
			if(a[i]%2==0){
				printf("1\n%d\n",i);
				flag=1;
				break;
			}
		}
		if(flag) continue;
		if(n==1) printf("-1\n");
		else printf("2\n1 2\n");
		
	}
	return 0;
}