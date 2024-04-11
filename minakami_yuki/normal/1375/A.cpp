#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int N=1e6+10;
int n,k;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(i&1){
				if(a[i]>0) a[i]=-a[i];
			}
			else {
				if(a[i]<0) a[i]=-a[i];
			}
			
		}
		for(int i=1;i<=n;++i) printf("%d ",a[i]);puts("");
	} 
	return 0;
}