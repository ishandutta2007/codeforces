#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > ans;


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
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};

int n;
vector<int> ___deg;

void fail(){
	cout << -1 << '\n';
	exit(0);
}

#define _assert(x) if(!(x)) {fail();}

void finish(){
	vector<int> cdeg(n, 0);
	UF uf(n);
	for(pair<int,int> x : ans){
		uf.join(x.first, x.second);
		cdeg[x.first] ++;
		cdeg[x.second]++;
	}
	for(int i = 0; i < n; i++){
		if(uf.find(i) != uf.find(0)) fail();
	}
	cout << ans.size() << '\n';
	for(pair<int,int> x : ans){
		cout << 2 << ' ' << x.first + 1 << ' ' << x.second + 1 << '\n';
	}
	cout << flush;
	for(int i = 0; i < n; i++){
		_assert(cdeg[i] == ___deg[i]);
	}
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int> d(n);
	int sd = 0;
	for(int i = 0; i < n; i++){
		cin >> d[i];
		sd += d[i];
	}
	___deg = d;
	if(sd & 1){
		fail();
	}
	int m = sd / 2;
	if(m < n-1) fail();
	vector<int> exists;
	for(int i = 0; i < n; i++){
		exists.push_back(i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(d[i] == 1 && (d[j] & 1) && d[j] >= 3){
				d[i]--;
				d[j]--;
				exists.erase(find(exists.begin(), exists.end(), i));
				ans.push_back({i, j});
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(d[i] == 1 && d[j] >= 4){
				int z = 0;
				while(z < n && (z == i || z == j || d[z] != 1)) z++;
				if(z == n || d[z] != 1) fail();
				exists.erase(find(exists.begin(), exists.end(), i));
				exists.erase(find(exists.begin(), exists.end(), z));
				d[i]--;
				d[j]--;
				d[z]--;
				d[j]--;
				ans.push_back({i, j});
				ans.push_back({z, j});
			}
		}
	}

	vector<int> leaves;
	for(int i = 0; i < n; i++){
		if(d[i] == 1) leaves.push_back(i);
	}
	if(!leaves.empty()){
		if(leaves.size() != 2) fail();
		for(int x : exists) if(d[x] > 2 || d[x] <= 0) fail();
		vector<int> p = leaves;
		for(int x : exists) if(d[x] == 2) p.insert(p.begin() + 1, x);
		for(int i = 0; i + 1 < (int)p.size(); i++) ans.push_back({p[i], p[i+1]});
		finish();
	}

	while(true){
		bool did = false;
		for(int x = 0; x < n; x++){
			if(d[x] & 1){
				_assert(d[x] != 1);
				int y = 0;
				while(y < n && (x == y || (d[y] & 1) == 0)) y++;
				_assert(y < n);
				did = true;
				int need2 = d[x] - 1;
				vector<int> twos;

				for(int i : exists){
					if(need2 == 0) break;
					if(d[i] == 2){
						twos.push_back(i);
						need2--;
					}
				}
				if(need2) fail();

				ans.push_back({x, y});
				d[x]--;
				d[y]--;
				exists.erase(find(exists.begin(), exists.end(), x));
				for(int a : twos){
					exists.erase(find(exists.begin(), exists.end(), a));
				}
				for(int i = 0; i < (int)twos.size(); i += 2){
					ans.push_back({x, twos[i]});
					ans.push_back({x, twos[i+1]});
					ans.push_back({twos[i], twos[i+1]});
					d[x] -= 2;
					d[twos[i]] -= 2;
					d[twos[i+1]] -= 2;
				}
			}
		}
		if(!did) break;
	}
	while(true){
		bool did = false;
		for(int x = 0; x < n; x++){
			if(d[x] >= 4){
				_assert(d[x] % 2 == 0);
				did = true;
				int need2 = d[x] - 2;
				vector<int> twos;

				for(int i : exists){
					if(need2 == 0) break;
					if(d[i] == 2){
						twos.push_back(i);
						need2--;
					}
				}
				if(need2) fail();

				for(int a : twos){
					exists.erase(find(exists.begin(), exists.end(), a));
				}
				for(int i = 0; i < (int)twos.size(); i += 2){
					ans.push_back({x, twos[i]});
					ans.push_back({x, twos[i+1]});
					ans.push_back({twos[i], twos[i+1]});
					d[x] -= 2;
					d[twos[i]] -= 2;
					d[twos[i+1]] -= 2;
				}
			}
		}
		if(!did) break;
	}
	if(exists.size() == 1) fail();
	if(exists.size() == 2) fail();
	for(int i = 0; i < (int)exists.size(); i++){
		if(d[exists[i]] != 2) fail();
	}
	for(int i = 0; i < (int)exists.size(); i++){
		ans.push_back({exists[i], exists[(i+1) % (int)exists.size()]});
	}

	finish();
}