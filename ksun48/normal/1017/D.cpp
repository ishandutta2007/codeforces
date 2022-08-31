#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 4096;

vector<int> answers[MAXN];
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, q, m;
	cin >> n >> m >> q;
	vector<int> w(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	while(w.size() < 12) w.push_back(0);
	n = 12;

	vector<pair<int,int> > stuff[MAXN];
	vector<int> freq(MAXN, 0);
	for(int j = 0; j < m; j++){
		string s;
		cin >> s;
		while(s.size() < 12) s += '0';
		int num = 0;
		for(int i = 0; i < n; i++){
			num |= ((s[i]-'0') << i);
		}
		freq[num]++;
	}
	vector<int> score(MAXN);
	for(int j = 0; j < MAXN; j++){
		score[j] = 0;
		for(int i = 0; i < n; i++){
			if(j & (1 << i)){
				score[j] += w[i];
			}
		}
	}
	for(int r = 0; r < MAXN; r++){
		answers[r].resize(101, 0);
	}
	LL g = (1 << n) - 1;
	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++){
			int f = score[i ^ j ^ g];
			if(f <= 100){
				answers[i][f] += freq[j];
			}
		}
	}
	for(int i = 0; i < MAXN; i++){
		for(int j = 1; j < answers[i].size(); j++){
			answers[i][j] += answers[i][j-1];
		}
	}

	for(int j = 0; j < q; j++){
		string s;
		cin >> s;
		while(s.size() < 12) s += '0';
		int num = 0;
		for(int i = 0; i < n; i++){
			num |= ((s[i]-'0') << i);
		}
		int k;
		cin >> k;
		cout << answers[num][k] << '\n';
	}
	return 0;
}