#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1001000027;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> freq(101, 0);
	vector<vector<LL> > knap(101, vector<LL>(11000, 0));
	knap[0][0] = 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		freq[a[i]]++;
		vector<vector<LL> > s(101, vector<LL>(11000, 0));
		for(int b = 0; b <= 100; b++){
			for(int f = 0; f <= 10000; f++){
				if(knap[b][f] == 0) continue;
				s[b][f] += knap[b][f];
				s[b][f] %= MOD;
				s[b+1][f+a[i]] += knap[b][f];
				s[b+1][f+a[i]] %= MOD;
			}
		}
		knap = s;
	}
	LL ncr[110][110];
	for(LL n = 0; n <= 100; n++){
		for(LL k = 0; k <= 100; k++){
			if(k > n){
				ncr[n][k] = 0;
			} else if(k == 0 || k == n){
				ncr[n][k] = 1;
			} else {
				ncr[n][k] = (ncr[n-1][k] + ncr[n-1][k-1]) % MOD;
			}
		}
	}

	int best = 0;
	int types = 0;
	for(int d = 1; d <= 100; d++){
		if(freq[d] > 0) types++;
	}
	for(int d = 1; d <= 100; d++){
		for(int num = 1; num <= freq[d]; num++){
			if(knap[num][d*num] == ncr[freq[d]][num]){
				best = max(best, num);
				if(num == freq[d] && types <= 2){
					best = n;
				}
			}
		}
	}
	cout << best << '\n';
}