#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int N=1e6+10;
int n,k,m;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		if(a[1]>a[n]) printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}