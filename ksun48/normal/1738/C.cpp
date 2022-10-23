#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> cnt(2);
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		cnt[x & 1]++;
	}
	const int MAXN = 101;
	vector<vector<vector<int> > > dpA(MAXN, vector<vector<int> >(MAXN, vector<int>(2, 0)));
	vector<vector<vector<int> > > dpB(MAXN, vector<vector<int> >(MAXN, vector<int>(2, 0)));
	for(int a = 0; a < MAXN; a++){
		for(int b = 0; b < MAXN; b++){
			for(int st = 0; st < 2; st++){
				if(a == 0 && b == 0){
					dpA[a][b][st] = !st;
					dpB[a][b][st] = !st;
				} else {
					dpA[a][b][st] = 0;
					if(a && dpB[a-1][b][st]) dpA[a][b][st] = 1;
					if(b && dpB[a][b-1][st^1]) dpA[a][b][st] = 1;
					dpB[a][b][st] = 1;
					if(a && !dpA[a-1][b][st]) dpB[a][b][st] = 0;
					if(b && !dpA[a][b-1][st]) dpB[a][b][st] = 0;
				}
			}
		}
	}
	cout << (dpA[cnt[0]][cnt[1]][0] ? "Alice" : "Bob") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}