#include <bits/stdc++.h>
using namespace std;

const int NN = 2000;

struct T {
  bool rr;
  T *son[2], *pf, *fa;
} f1[NN], *ff = f1, *f[NN], *null;

void downdate(T *x) {
  if (x -> rr) {
    x -> son[0] -> rr = !x -> son[0] -> rr;
    x -> son[1] -> rr = !x -> son[1] -> rr;
    swap(x -> son[0], x -> son[1]);
    x -> rr = false;
  }
  // add stuff
}

void update(T *x) {
  // add stuff
}

void rotate(T *x, bool t) { /// start-hash
  T *y = x -> fa, *z = y -> fa;
  if (z != null)  z -> son[z -> son[1] == y] = x;
  x -> fa = z;
  y -> son[t] = x -> son[!t];
  x -> son[!t] -> fa = y;
  x -> son[!t] = y;
  y -> fa = x;
  update(y);
} /// end-hash

void xiao(T *x) {
  if (x -> fa != null)  xiao(x -> fa), x -> pf = x -> fa -> pf;
  downdate(x);
}

void splay(T *x) { /// start-hash
  xiao(x);
  T *y, *z;
  while (x -> fa != null) {
    y = x -> fa; z = y -> fa;
    bool t1 = (y -> son[1] == x), t2 = (z -> son[1] == y);
    if (z != null) {
      if (t1 == t2) rotate(y, t2), rotate(x, t1);
      else  rotate(x, t1), rotate(x, t2);
    }else rotate(x, t1);
  }
  update(x);
} /// end-hash

void access(T *x) {/// start-hash
  splay(x);
  x -> son[1] -> pf = x;
  x -> son[1] -> fa = null;
  x -> son[1] = null;
  update(x);
  while (x -> pf != null) {
    splay(x -> pf);
    x -> pf -> son[1] -> pf = x -> pf;
    x -> pf -> son[1] -> fa = null;
    x -> pf -> son[1] = x;
    x -> fa = x -> pf;
    splay(x);
  }
  x -> rr = true;
} /// end-hash

bool Cut(T *x, T *y) { /// start-hash
  access(x);
  access(y);
  downdate(y);
  downdate(x);
  if (y -> son[1] != x || x -> son[0] != null)
    return false;
  y -> son[1] = null;
  x -> fa = x -> pf = null;
  update(x);
  update(y);
  return true;
} /// end-hash

bool Connected(T *x, T *y) {
  access(x);
  access(y);
  return x == y || x -> fa != null;
}

bool Link(T *x, T *y) {
  if (Connected(x, y))
    return false;
  access(x);
  access(y);
  x -> pf = y;
  return true;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];

	ff = f1;

	null = new T; null -> son[0] = null -> son[1] = null -> fa = null -> pf = null;
	for (int i = 0; i < n * m; i++) {
		f[i] = ++ff;
		f[i] -> son[0] = f[i] -> son[1] = f[i] -> fa = f[i] -> pf = null;
		f[i] -> rr = false;
	}
	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};
	vector<set<int> > used(n * m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 && j == 0) continue;
			if(s[i][j] == 'X') continue;
			if(((i + j) & 1) == 0){
				int a = m * i + j;
				for(int d = 0; d < 4; d++){
					if(used[a].size() == 2) continue;
					int ni = i + dx[d];
					int nj = j + dy[d];
					if(ni < 0 || nj < 0 || ni >= n || nj >= m || s[ni][nj] == 'X') continue;
					int b = m * ni + nj;
					while(true){
						if(!Connected(f[a], f[b])){
							used[a].insert(b);
							used[b].insert(a);
							Link(f[a], f[b]);
							break;
						}
						bool done = false;
						for(int v = 0; v < n; v++){
							for(int w = 0; w < m; w++){
								if(((v + w) & 1) != 0) continue;
								int c = m * v + w;
								if(!Connected(f[a], f[c])) continue;
								for(int d1 = 0; d1 < 4; d1++){
									int nv = v + dx[d1];
									int nw = w + dy[d1];
									if(nv < 0 || nw < 0 || nv >= n || nw >= m || s[nv][nw] == 'X') continue;
									int nc = nv * m + nw;
									if(Connected(f[a], f[nc])) continue;
									done = true;
									for(int bc : used[c]){
										assert(Cut(f[c], f[bc]));
										if(!Connected(f[a], f[c])){
											used[c].erase(bc);
											used[bc].erase(c);
											break;
										}
										Link(f[c], f[bc]);
									}
									used[c].insert(nc);
									used[nc].insert(c);
									Link(f[c], f[nc]);
									goto found;
								}
							}
						}
						found:;

						if(!done) break;
					}
				}
				if(used[a].size() < 2){
					cout << "NO" << '\n';
					return;
				}
			}
		}
	}
	cout << "YES" << '\n';
	vector<string> ans(2*n-1, string(2*m-1, ' '));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans[2*i][2*j] = s[i][j];
			if(s[i][j] == 'X') continue;
			if(((i + j) & 1) == 0){
				int a = m * i + j;
				for(int d = 0; d < 4; d++){
					int ni = i + dx[d];
					int nj = j + dy[d];
					if(ni < 0 || nj < 0 || ni >= n || nj >= m || s[ni][nj] == 'X') continue;
					int b = m * ni + nj;
					if(!Connected(f[a], f[b])){
						used[a].insert(b);
						used[b].insert(a);
						Link(f[a], f[b]);
					}
					if(used[a].count(b)){
						ans[2*i + dx[d]][2*j + dy[d]] = 'O';
					}
				}
			}
		}
	}
	for(string z : ans){
		cout << z << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}