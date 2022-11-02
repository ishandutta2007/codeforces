#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int dp[2500];

void print(int k) {
	if(k == 0)
		cout<<"Bob\n";
	else
		cout<<"Alice\n";
}

int main() {
	for(int i=0;i<2400;i++) {
		for(int j=2;j*j<=i;j++) {
			if(i%j != 0)
				continue;
				
			if(dp[i-j] == 0)
				dp[i] = 1;
			if(dp[i-(i/j)] == 0)
				dp[i] = 1;
		}
	}
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		int N = n, counti = 0;
		while(N%2 == 0)
			N/=2, counti++;
		if(N == 1) {
			if(n < 1000)
				print(dp[n]);
			else
				print(1-counti%2);
			continue;
		}
		if(n < 1000)
			print(dp[n]);
		else
			print(1-n%2);
	}
	return 0;
}