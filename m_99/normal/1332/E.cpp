#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000

pair<int,int> calc(pair<int,int> A,pair<int,int> B){
	pair<int,int> ret;
	ret.first = mod(mod(A.first*B.first)+mod(A.second*B.second));
	ret.second = mod(mod(A.first*B.second)+mod(A.second*B.first));
	return ret;
}

int main() {
	
	long long n,m,L,R;
	cin>>n>>m>>L>>R;
	
	long long K = n*m;
	
	pair<int,int> now = {1,0};
	pair<int,int> temp = {R/2 - (L-1)/2,(R+1)/2 - L/2};
	
	while(K!=0){
		if(K%2==1){
			now = calc(now,temp);
		}
		temp = calc(temp,temp);
		K/=2;
	}
	
	if(n*m%2==0){
		cout<<now.first<<endl;
	}
	else{
		cout<<mod(now.first+now.second);
	}
	
    return 0;
}