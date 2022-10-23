#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N;
	cin >> N;
	auto ask = [&](vector<int> v){
		int k = (int)v.size();
		cout << "? " << k;
		for(int x : v) cout << ' ' << (x+1);
		cout << '\n';
		cout << flush;
		string ret;
		cin >> ret;
		return (ret == "YES");
	};
	auto guess = [&](int x){
		cout << "! " << (x+1) << '\n';
		cout << flush;
		string res;
		cin >> res;
		return (res == ":)");
	};
	vector<int> yes;
	vector<int> no;
	for(int i = 0; i < N; i++) yes.push_back(i);
	int ops = 0;
	const int D = 1000;
	vector<vector<int> > a(D+1, vector<int> (D+1));
	vector<vector<pair<int,int> > > nxt(D+1, vector<pair<int,int> > (D+1));

	int INF = 2305897;
	for(int S = 0; S <= D; S++){
		for(int x = 0; x <= S; x++){
			int y = S-x;
			if(x + y <= 2){
				a[x][y] = 0;
			} else {
				a[x][y] = INF;
				for(int r = x/2-4; r <= x/2+4; r++){
					for(int s = y/2-4; s <= y/2+4; s++){
						if(r < 0 || s < 0 || r > x || s > y) continue;
						int bposs = 0;
						for(pair<int,int> z : {pair<int,int>{r + s, x - r}, pair<int,int>{x + y - r - s, r}}){
							auto [nx, ny] = z;
							if(nx + ny > S){
								bposs = INF;
							} else if((nx + ny == S) && ny <= y){
								bposs = INF;
							} else {
								bposs = max(bposs, a[nx][ny] + 1);
							}
						}
						if(bposs < a[x][y]){
							a[x][y] = bposs;
							nxt[x][y] = {r, s};
						}
					}
				}
			}
		}
	}
	while(yes.size() + no.size() > 2){
		vector<int> tot = yes;
		tot.insert(tot.end(), no.begin(), no.end());
		vector<int> S;
		vector<int> inS;
		int X = (int)yes.size();
		int Y = (int)no.size();
		if(X + Y <= D){
			auto [r, s] = nxt[X][Y];
			for(int j = 0; j < r; j++){
				S.push_back(tot[j]);
				inS.push_back(1);
			}
			for(int j = r; j < X; j++) inS.push_back(0);
			for(int j = X; j < X+s; j++){
				S.push_back(tot[j]);
				inS.push_back(1);
			}
			for(int j = X+s; j < X+Y; j++) inS.push_back(0);
		} else {
			for(int j = 0; j < (int)tot.size(); j++){
				if((j & 1)){
					S.push_back(tot[j]);
				}
				inS.push_back(j & 1);
			}
		}
		bool res = ask(S);
		vector<int> nyes, nno;
		for(int j = 0; j < (int)tot.size(); j++){
			bool yes1 = (j < X);
			bool yes2 = (res == inS[j]);
			if(yes2){
				nyes.push_back(tot[j]);
			} else if(yes1){
				nno.push_back(tot[j]);
			}
		}
		yes = nyes;
		no = nno;
		ops++;
		// cerr << ops << ' ' << yes.size() << ' ' << no.size() << '\n';
	}
	vector<int> tot = yes;
	tot.insert(tot.end(), no.begin(), no.end());
	for(int x : tot){
		bool res = guess(x);
		if(res) break;
	}
}