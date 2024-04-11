#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
int sm[N]; bool npr[N];
void pr(){
	npr[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!npr[i]){
			for(int j=i;j<=1000000/i;j++)
				if(!npr[i*j]) sm[i*j]=i,npr[i*j]=1;
		}
	}
}
signed main(){
	int T; cin>>T;
	pr();
	while(T--){
		int n,k; scanf("%lld%lld",&n,&k);
		if(!npr[n]){
			printf("%lld\n",2*(n+k-1));
		}else if(sm[n]==2){
			printf("%lld\n",n+2*k);
		}else{
			printf("%lld\n",n+sm[n]+2*(k-1));
		}
	}
	return 0;
}