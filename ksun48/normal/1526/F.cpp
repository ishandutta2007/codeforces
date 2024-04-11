#include <bits/stdc++.h>
using namespace std;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
mt19937 mt2(48);

const bool TEST = false;
vector<int> P;
int NQ = 0;

void init(int n){
	if(TEST){
		NQ = 0;
		P.resize(n);
		for(int i = 0; i < n; i++) P[i] = i;
		while(true){
			shuffle(P.begin(), P.end(), mt2);
			if(P[0] < P[1]) break;
		}		
	}
}

int ask(int a, int b, int c){
	assert(a != b && a != c && b != c);
	if(TEST){
		NQ++;
		vector<int> d = {abs(P[a] - P[b]), abs(P[a] - P[c]), abs(P[b] - P[c])};
		sort(d.begin(), d.end());
		return d[1];
	}
	cout << "? ";
	cout << (a+1) << ' ' << (b+1) << ' ' << (c+1) << '\n';
	cout << flush;
	int r;
	cin >> r;
	if(r == -1) assert(false);
	return r;
}

void answer(vector<int> p){
	cout << "!";
	for(int x : p){
		cout << " " << (x+1);
	}
	cout << '\n';
	cout << flush;
	if(TEST){
		assert(p == P);
		assert(NQ <= 2 * (P.size()) + 420);
	} else {
		int r;
		cin >> r;
		assert(r == 1);		
	}
}

void solve(){
	int n;
	if(TEST){
		n = 20 + (mt2() % (1 << (mt2() % 10)));
		init(n);
	} else {
		cin >> n;
	}
	int a, b, c;
	while(true){
		a = mt() % n;
		b = mt() % n;
		c = mt() % n;
		if(a == b || a == c || b == c) continue;
		int res = ask(a, b, c);
		if(res <= n/6 - 1){
			break;
		}
	}
	vector<int> dist(n);
	for(int i = 0; i < n; i++){
		if(i == a || i == b) {
			dist[i] = -1;
		} else {
			dist[i] = ask(a, b, i);
		}
	}
	vector<int> ord(n);
	for(int i = 0; i < n; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int x, int y) { return dist[x] > dist[y]; } );
	vector<vector<int> > h;
	int st = 0;
	for(int j = 0; j < 3; j++){
		vector<int> z;
		int d;
		for(d = st; d < n && dist[ord[d]] == dist[ord[st]]; d++){
			z.push_back(ord[d]);
		}
		h.push_back(z);
		st = d;
		if(z.size() > 2){
			cerr << P[a] << ' ' << P[b] << ' ' << P[c] << '\n';
		}
		assert(z.size() <= 2);
	}
	int r0 = -1, r1 = -1;
	for(int x : h[0]){
		for(int y : h[1]){
			for(int z : h[2]){
				if(ask(x, y, z) == 1){
					r0 = x;
					r1 = y;
				}
			}
		}
	}
	assert(r0 >= 0);
	vector<int> p(n, -1);
	for(int i = 0; i < n; i++){
		if(i == r0){
			p[i] = 0;
		} else if(i == r1){
			p[i] = 1;
		} else {
			p[i] = 1 + ask(r0, r1, i);
		}
	}
	if(p[0] > p[1]){
		for(int& x : p){
			x = n-1-x;
		}
	}
	answer(p);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}