#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int pc(int x){
	return x==0?0:pc(x>>1)+(x&1);
}
int main(){
	LL n,p;
	cin>>n>>p;
	for(int i=0;i<1000000;i++){
		LL q=n-i*p;
		if(q>=i&&pc(q)<=i){
			printf("%d\n",i);
			exit(0);
		}
	}
	puts("-1");
	return 0;
}