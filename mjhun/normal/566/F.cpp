#include <cstdio>
#include <iostream>
using namespace std;
#define N 1000000

int v[1<<20];

int main(){
	int n,x,r;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		v[x]=1;
	}
	r=1;
	for(int i=1;i<=N;++i){
		if(v[i]){
			r=max(r,v[i]);
			for(int j=i+i;j<=N;j+=i){
				if(v[j]){
					v[j]=max(v[j],v[i]+1);
				}
			}
		}
	}
	printf("%d\n",r);
	return 0;
}