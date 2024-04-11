#include <bits/stdc++.h>
using namespace std;

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m1, m2;
	cin >> n;
	cin >> m1 >> m2;
	UF uf1(n), uf2(n);
	for(int i = 0; i < m1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf1.join(a, b);
	}
	for(int i = 0; i < m2; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf2.join(a, b);
	}
	vector<pair<int,int> > added;
	vector<int> vert_queue;

	auto okay = [&](int x, int y) -> bool {
		if(uf1.find(x) != uf1.find(y) && uf2.find(x) != uf2.find(y)){
			uf1.join(x, y);
			uf2.join(x, y);
			added.push_back({x, y});
			return true;
		}
		return false;
	};

	int which = 1;
	for(int x = 0; x < n; x++){
		if(vert_queue.empty()){
			vert_queue = {x};
			which = 1;
			continue;
		}
		UF& ufa = (which == 2) ? uf2 : uf1;
		if(ufa.find(vert_queue.back()) == ufa.find(x)){
			vert_queue.push_back(x);
		} else {
			while(vert_queue.size() >= 2){
				int p = vert_queue.back();
				vert_queue.pop_back();
				int q = vert_queue.back();
				vert_queue.pop_back();
				if(okay(p, x)){
					vert_queue.push_back(x);
					vert_queue.push_back(q);
					goto done;
				} else if(okay(q, x)){
					vert_queue.push_back(x);
					vert_queue.push_back(p);
					goto done;
				} else {
					vert_queue.push_back(p);
				}
			}
			if(!okay(vert_queue.back(), x)){
				which = (uf1.find(vert_queue.back()) == uf1.find(x)) ? 1 : 2;
				vert_queue.push_back(x);
			}
			done:;
		}
	}
	cout << added.size() << '\n';
	for(auto [a, b] : added){
		cout << (a+1) << ' ' << (b+1) << '\n';
	}
}