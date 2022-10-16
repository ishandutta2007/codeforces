#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


string A, B;

const int MaxLen = 200005,
          Mod = 1000000007;

int K[MaxLen];
int dp[MaxLen], dpnot[MaxLen],  dpnotsum[MaxLen];

void kmp(string s){
	K[0] = 0;
	K[1] = 0;
	for(int i = 1; i < s.length(); i++){
		K[i+1] = K[i];
		while(K[i+1] > 0 && s[i] != s[K[i+1]]) K[i+1] = K[K[i+1]];
		if(s[i] == s[K[i+1]]) K[i+1]++;
//		printf("%d ", K[i+1]);
	}
//	printf("\n");
}

void input(){
	cin >> A >> B;

}



int main(){
	ios_base::sync_with_stdio(0);
	input();
	kmp(B + "$" + A);
	
	int offset = B.size(), length = A.size();
	dp[0] = 0; dpnot[0] = 1; dpnotsum[0] = 1;
	int where = -1;
	int total = 0;

	for(int i = 1; i <= length; i++){
		if(K[1+offset+i] == offset){
			where = i;
		}
//		printf("%d\n", where);
		if(where == -1){
			dp[i] = 1;
			dpnot[i] = dpnot[i-1];
			dpnotsum[i] = (dpnotsum[i-1] + dpnot[i-1]) % Mod;
			continue;
		}
		dp[i] = dpnotsum[where-offset];
		total = (total + dp[i]) % Mod;
		dpnot[i] = (dpnot[i-1] + dp[i]) % Mod;
		dpnotsum[i] = (dpnotsum[i-1] + dpnot[i]) % Mod;
//		printf("%d(%d) ", dp[i], dpnotsum[i]);
	}

	printf("%d\n", total);
}