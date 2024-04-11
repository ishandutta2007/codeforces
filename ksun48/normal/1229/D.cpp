#include <bits/stdc++.h>
using namespace std;

const int N = 6;
const int n = 5;

struct Perm {
  int a[N];
  Perm() {
    for (int i = 1; i <= n; ++i) a[i] = i;
  }
  friend Perm operator* (const Perm &lhs, const Perm &rhs) {
    static Perm res;
    for (int i = 1; i <= n; ++i) res.a[i] = lhs.a[rhs.a[i]];
    return res;
  }
  friend Perm inv(const Perm &cur) {
    static Perm res;
    for (int i = 1; i <= n; ++i) res.a[cur.a[i]] = i;
    return res;
  }
};
class Group {
public:
  bool flag[N];
  Perm w[N];
  std::vector<Perm> x;

  void clear(int p) {
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= n; ++i) w[i] = Perm();
    flag[p] = true;
    x.clear();
  }
  friend bool check(vector<Group>& g, const Perm&, int);
  friend void insert(vector<Group>& g, const Perm&, int);
  friend void updateX(vector<Group>& g, const Perm&, int);
};
bool check(vector<Group>& g, const Perm &cur, int k) {
  if (!k) return true;
  int t = cur.a[k];
  return g[k].flag[t] ? check(g, g[k].w[t] * cur, k - 1) : false;
}
void updateX(vector<Group>& g, const Perm&, int);
void insert(vector<Group>& g, const Perm &cur, int k) {
  if (check(g, cur, k)) return;
  g[k].x.push_back(cur);
  for (int i = 1; i <= n; ++i) if (g[k].flag[i]) updateX(g, cur * inv(g[k].w[i]), k);
}
void updateX(vector<Group>& g, const Perm &cur, int k) {
  int t = cur.a[k];
  if (g[k].flag[t]) {
    insert(g, g[k].w[t] * cur, k - 1);
  } else {
    g[k].w[t] = inv(cur);
    g[k].flag[t] = true;
    for (int i = 0; i < g[k].x.size(); ++i) updateX(g, g[k].x[i] * cur, k);
  }
}
vector<Group> emp(){
	vector<Group> a(N);
	for(int i = 1; i <= n; i++){
		a[i].clear(i);
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int len, k;
	cin >> len >> k;
	vector<Perm> p(len);
	for(int i = 0; i < len; i++){
		for(int j = 1; j <= k; j++){
			cin >> p[i].a[j];
		}
	}
	using ll = long long;
	ll ans = 0;
	vector<pair<vector<Group>, int> > cur_groups;
	for(int i = 0; i < len; i++){
		cur_groups.push_back({emp(), 1});
		vector<int> cnts;
		for(auto& r : cur_groups){
			insert(r.first, p[i], n);
			int cnt = 1;

			for(int i = 1; i <= n; i++){
				int f = 0;
				for(int j = 1; j <= n; j++){
					f += r.first[i].flag[j];
				}
				cnt *= f;
			}
			cnts.push_back(cnt);
		}
		for(int i = 0; i < cnts.size(); i++){
			ans += ll(cur_groups[i].second) * ll(cnts[i]);
		}
		for(int i = (int)cnts.size()-1; i > 0; i--){
			if(cnts[i] == cnts[i-1]){
				cur_groups[i-1].second += cur_groups[i].second;
				cur_groups.erase(cur_groups.begin() + i);
			}
		}
	}
	cout << ans << '\n';
}