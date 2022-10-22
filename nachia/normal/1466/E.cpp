#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const ULL M=1000000007;
ULL D[60];

int N;
ULL X[500000];
int C[60];

void loop(){
	scanf("%d",&N);
	rep(i,N) scanf("%llu",&X[i]);

	rep(d,60){ C[d]=0; rep(i,N) if(X[i]&(1ull<<d)) C[d]++; }

	ULL ans=0;
	rep(j,N){
		ULL sumOR=0, sumAND=0;
		rep(d,60){
			if(X[j]&(1ull<<d)){
				sumAND+=D[d]*C[d];
				sumOR+=D[d]*N;
			}
			else{
				sumAND+=0;
				sumOR+=D[d]*(C[d]);
			}
		}
		sumOR%=M;
		sumAND%=M;
		ans+=sumOR*sumAND; ans%=M;
	}
	printf("%llu\n",ans);
}

int main(){
	rep(d,60) D[d]=(1ull<<d)%M;
	int T; scanf("%d",&T);
	while(T--) loop();
	return 0;
}