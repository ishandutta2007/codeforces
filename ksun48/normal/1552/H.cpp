#include <bits/stdc++.h>
using namespace std;

const int N = 200;

int nq = 0;

int ask(int a, int dir){
	nq++;
	if(nq > 4) assert(false);
	vector<pair<int,int> > p;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i % a == 0) p.push_back({dir ? i : j, dir ? j : i});
		}
	}
	cout << "? " << p.size() << '\n';
	for(auto [x, y] : p){
		cout << (x+1) << ' ' << (y+1) << ' ';
	}
	cout << '\n';
	cout << flush;
	cerr << "hint: " << a << ' ' << dir << '\n';
	int cnt;
	cin >> cnt;
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int A = ask(1, 0);
	vector<int> cand;
	for(int g = 1; g <= A; g++){
		if(A % g == 0 && g > 1 && g <= N && A / g > 1 && A / g <= N) cand.push_back(g);
	}
	while(cand.size() > 1){
		int best = (int)cand.size() + 1;
		map<int, set<int> > bestz;
		int bestl = -1;
		int which = -1;
		if(cand.size() <= 1) return 0;
		for(int l = 1; l <= A; l++){
			map<int, set<int>> z;
			for(int a : cand){
				int b = A / a;
				int maxv = (b) * (1 + (a-1) / l);
				int minv = (b) * (a / l);
				z[maxv].insert(a);
				z[minv].insert(a);
			}
			int maxsize = 0;
			for(auto [k, res] : z){
				maxsize = max(maxsize, (int)res.size());
			}
			if(maxsize < best){
				bestz = z;
				bestl = l;
				best = maxsize;
				which = 0;
			}
		}
		for(int l = 1; l <= A; l++){
			map<int, set<int>> z;
			for(int a : cand){
				int b = A / a;
				int maxv = (a) * (1 + (b-1) / l);
				int minv = (a) * (b / l);
				z[maxv].insert(a);
				z[minv].insert(a);
			}
			int maxsize = 0;
			for(auto [k, res] : z){
				maxsize = max(maxsize, (int)res.size());
			}
			if(maxsize < best){
				bestz = z;
				bestl = l;
				best = maxsize;
				which = 1;
			}
		}
		assert(bestl >= 0);
		int cnt = ask(bestl, which);
		assert(bestz.count(cnt));
		set<int> r = bestz[cnt];
		cand = vector<int>(r.begin(), r.end());
	}
	assert(!cand.empty());
	int a = cand.front();
	int b = A / a;
	cout << "! " << (2 * a + 2 * b - 4) << '\n';
}