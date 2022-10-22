#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n;
	cin>>n;
	n/=2;
	vector<long long> b(n);
	rep(i,n){
		scanf("%lld",&b[i]);
	}
	
	vector<long long> x,y;
	
	rep(i,n){
		if(i==0){
			x.push_back(0);
			y.push_back(b[0]);
		}
		else{
			x.push_back(x.back());
			y.push_back(y.back());
			
			long long t = x.back() + y.back();
			
			if(t==b[i])continue;
			if(t>b[i]){
				y.back() -= t-b[i];
			}
			else{
				x.back() += b[i]-t;
			}
		}
	}
	
	rep(i,n){
		x.push_back(y.back());
		y.pop_back();
	}
	
	rep(i,2*n){
		if(i!=0)printf(" ");
		printf("%lld",x[i]);
	}
	cout<<endl;
	
	
	
    return 0;
}