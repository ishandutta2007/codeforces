#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300

int digit_sum(long long n){
	int ret = 0;
	while(n!=0){
		ret += n%10;
		n/=10;
	}
	return ret;
}

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		long long n,s;
		cin>>n>>s;
		long long copy = n;
		while(digit_sum(n)>s){
			int cnt = 0;
			while(n%10==0){
				cnt++;
				n/=10;
			}
			n/=10;
			n++;
			n*=10;
			rep(i,cnt)n*=10;			
		}
		
		cout<<n-copy<<endl;
		
	}
	
    return 0;
}