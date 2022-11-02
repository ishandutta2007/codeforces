#include <iostream>
using namespace std;

int dp[50];

int main() {
	int T; cin>>T;
	while(T--) {
		long long n; cin>>n;
		n = ((n+1)/2)*2;
		if(n <= 6) {
			cout<<15<<endl;
		}
		else {
			cout<<5*(n/2)<<endl;
		}
	}
	return 0;
}