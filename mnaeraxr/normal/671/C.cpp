#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int maxa = 200000 + 1;

vi D[maxa];
vi S[maxa];

/*
10
6 9 15 2 3 7 8 10 1 14

9
4 10 11 6 5 3 12 13 2

 */

void buildDiv(){
	for (int i = 1; i < maxa; ++i)
		for (int j = i; j < maxa; j += i)
			D[j].push_back(i);
}

struct event{
	int64 x, y, g;

	bool operator <(const event &e) const{
		return y < e.y;
	}
};

void push(vector<event> &E, event e){
	if (e.x < e.y){
//		cout << e.x  << " " << e.y << " " << e.g << endl;
		E.push_back(e);
	}
}

bool compareX(event a, event b){
	return a.x < b.x;
}

int64 solve(vector<event> E, int n){
	sort(E.begin(), E.end(), compareX);
	set<event> S;

	S.insert({0, n, 0});
	int64 ans = 0;
	int64 line = 0;
//	int cnt = 0;

	for (int i = 0, j = 0; i < n; ++i){
		while (!S.empty() && S.begin()->y == i){
			if (S.size() > 1){
				auto it = S.begin(); ++it;
				line -= (it->y - S.begin()->y) * it->g;
			}
			S.erase(S.begin());
		}

//		cout << "(s)step: " << i << endl;

		for (;j < (int)E.size() && E[j].x == i; ++j){
//			cout << "proc: " << E[j].y << " " << E[j].g << " " << S.size() << endl;
			auto it = S.upper_bound(E[j]);
			if (it != S.end() && it->g > E[j].g) continue;

			while (true){
				it = S.upper_bound(E[j]);

				if (it == S.begin()){
					line += (it->y - E[j].y) * it->g;
					S.insert(E[j]);
					break;
				}

				if (it == S.end()){
					if (E[j].g > S.rbegin()->g){
						if (S.size() == 1){
							S.erase(S.begin());
							S.insert(E[j]);
						}
						else{
							while (S.size() > 1 && E[j].g >= S.rbegin()->g){
								auto it = S.end();
								it--;
								auto jt = it;
								jt--;
								line -= (it->y - jt->y) * it->g;
								S.erase(it);
							}

							if (E[j].g >= S.rbegin()->g){
								S.erase(S.begin());
							}
							else{
								line += (E[j].y - S.rbegin()->y) * E[j].g;
							}

							S.insert(E[j]);
						}
					}
					break;
				}

//				cout << "HERE" << endl;

				event tmp = *it;
				it--;
//				cout << it->y << " " << it->g << endl;

				if (E[j].g >= it->g){
					if (it == S.begin())
						line -= (tmp.y - it->y) * tmp.g;
					else{
						auto jt = it;
						jt--;
						line += (it->y - jt->y) * (tmp.g - it->g);
					}
					S.erase(it);
				}
				else if (E[j].y == it->y){
					break;
				}
				else{
//					cout << "BOOM" << endl;
					line -= (tmp.y - it->y) * tmp.g;
					line += (E[j].y - it->y) * E[j].g;
					line += (tmp.y - E[j].y) * tmp.g;
					S.insert(E[j]);
					break;
				}
			}

//			cout << line << endl;
		}

//		cout << endl;
//		cout << "step: " << i << endl;
//		cout << "line=" << line << endl;
//		for (auto e : S) cout << "(" << e.y << ";" << e.g << ") ";
//		cout << endl;
//		cout << "row=" << line + S.begin()->g * (S.begin()->y - i) << endl << "=========" << endl;

//		if (++cnt == 2) exit(0);

		ans += line + S.begin()->g * (S.begin()->y - i);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	buildDiv();

	int n; cin >> n;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		for (auto d : D[v])
			S[d].push_back(i);
	}

	vector<event> E;

	for (int i = 1; i < maxa; ++i){
		int t = (int)S[i].size();
		if (t >= 2){
			push(E, {S[i][0] + 1, S[i].back(), i});
			push(E, {S[i][1] + 1, n, i});
			push(E, {0, S[i][t - 2], i});
		}
	}

	cout << solve(E, n) << endl;

	return 0;
}