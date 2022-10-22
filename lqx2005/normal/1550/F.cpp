#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
using namespace std;
const int N = 1e6 + 10, oo = 0x3f3f3f3f;
int n, q, s, d;
int a[N], vis[N], dis[N];
priority_queue<pair<int, int> > pq;
struct line_set {
	set<int> pos;
	set<pair<int, int> > t;
	line_set() {
		pos.insert(oo), pos.insert(-oo);
		t.insert(mp(oo, 0)), t.insert(mp(-oo, 0));
	}
	
	int change(int x, int y) {
//		cout << x <<" " << y << endl;
		auto it = t.upper_bound(mp(x, 0));
		while(it != t.begin()) {
			it--;
			if(abs(x - it -> x) + y <= it -> y) {
				t.erase(it);
			} else {
				break;
			}
			it = t.upper_bound(mp(x, 0));
		}
		t.insert(mp(x, y));
		auto f = pos.upper_bound(x);
		if(f == pos.begin()) return -oo;
		return *(--f);
	}
	
	vector<int> assign(int l, int r) {
		vector<int> crd;
		auto itl = pos.lower_bound(l), itr = pos.upper_bound(r);
		for(auto it = itl; it != itr; it++) {
			crd.push_back(*it);
		}
		pos.erase(itl, itr);
		return crd;
	}
	
	int query(int x) {
		auto it = t.lower_bound(mp(x, 0));
		return abs(it -> x - x) + it -> y;
	}
	
}in, de;


void Push(int x) {
	if(x <= -oo || x >= oo) return;
//	cout << in.query(- x) << endl;
	int val = min(de.query(x), in.query(-x));
	if(dis[x] > val)  {
		dis[x] = val;
		pq.push(mp(- val, x));
	}
	return;
}

void modify(int l, int r, int d) {
	vector<int> k = de.assign(l, r);
	in.assign(- r, - l);
	for(int i = 0; i < sz(k); i++) {
		pq.push(mp(- (dis[k[i]] = d), k[i]));
	}
	return;
}

void bfs() {
    memset(dis, 0x3f, sizeof(dis));
    pq.push(mp(0, a[s]));
    dis[a[s]] = 0;
    for(; !pq.empty(); ) {
        int x = pq.top().y, y = pq.top().x;
        pq.pop();
        if(vis[x] || dis[x] < y) continue;
        de.pos.erase(x), in.pos.erase(- x);
        modify(x - d - dis[x], x - d + dis[x], dis[x]);
        modify(x + d - dis[x], x + d + dis[x], dis[x]);
        vis[x] = 1;
        int a = de.change(x - d - dis[x], dis[x]);
        int b = de.change(x + d - dis[x], dis[x]);
        int c = in.change(- (x - d + dis[x]), dis[x]);
        int e = in.change(- (x + d + dis[x]), dis[x]);
        Push(a), Push(b), Push(- c), Push(- e);
    }
    return;
}

int main() {
    cin >> n >> q >> s >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        de.pos.insert(a[i]), in.pos.insert(- a[i]);
    }
    bfs();
    int x, k;
    for(; q--; ) {
        cin >> x >> k;
        if(dis[a[x]] <= k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}