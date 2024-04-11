#include <bits/stdc++.h>

using namespace std;

void upd(int &a, int b){
	a = min(a, b);
}

const int N = 20;
const int M = (1 << N) + 55;
const int INF = int(1e9) + 100;

int a, n;
string s;
int cnt[N][N];
int d[M][N];
int dp[M];
int cntBit[M];
int minBit[M];

int main() {	
	cin >> n >> a >> s;
	
	int B = (1 << a) - 1;
	for(int i = 1; i < s.size(); ++i){
		++cnt[s[i] - 'a'][s[i - 1] - 'a'];
		++cnt[s[i - 1] - 'a'][s[i] - 'a'];
	}
	for(int i = 0; i < M; ++i)
		dp[i] = INF;
	dp[0] = 0;
	for(int msk = 1; msk < M; ++msk){
		cntBit[msk] = 1 + cntBit[msk & (msk - 1)];
		for(int i = 0; i < N; ++i) if((msk >> i) & 1){
			minBit[msk] = i;
			break;
		}
	}
	for(int msk = 1; msk < M; ++msk)
		for(int i = 0; i < a; ++i){
			int b = minBit[msk];
			d[msk][i] = d[msk ^ (1 << b)][i] + cnt[i][b];		
		}

	for(int msk = 0; msk < (1 << a); ++msk){
		for(int i = 0; i < a; ++i){
			if((msk >> i) & 1) continue;
			//i -> x
			int pos = cntBit[msk];
			int nmsk = msk | (1 << i);
			upd(dp[nmsk], dp[msk] + pos * (d[msk][i] - d[B ^ nmsk][i]));
		}
	}	

	cout << dp[B] << endl;
	return 0;
}