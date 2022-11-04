#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; cin>>T;
	while(T--) {
		unsigned long long n,r;
		std::cin>>n>>r;
		if(n<=r) std::cout<<n*(n-1)/2+1<<std::endl;
		else std::cout<<r*(r+1)/2<<std::endl;
	}
	return 0;
}