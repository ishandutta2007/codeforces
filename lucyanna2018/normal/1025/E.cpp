#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int
// #define i128 __int128_t

#define ran 55
#define lim 10800

struct P {
	int x, y;
	P() {}
	P(int _x, int _y) { x = _x; y = _y; }
};

int n, m;
P fr[ran], to[ran];

vector<pair<P, P> > ans1, ans2;

const int go[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int q[ran*100], l, r;
bool visd[ran][ran];
pair<int, int> last[ran][ran];

void ins(int x, int y, int last_x, int last_y) {
	q[r++] = x; q[r++] = y;
	visd[x][y] = true;
	last[x][y] = make_pair(last_x, last_y);
}

bool get_path(P*pos, int id, int dest_x, int dest_y, vector<pair<P, P> > &steps) {
	memset(visd, false, sizeof visd);
	for(int i=1;i<=m;i++)
		visd[pos[i].x][pos[i].y] = true;
	
	l = r = 0;
	ins(pos[id].x, pos[id].y, -1, -1);
	while(l<r) {
		int x = q[l++], y = q[l++];
		for(int i=0;i<4;i++) {
			int nxt_x = x+go[i][0], nxt_y = y+go[i][1];
			if (nxt_x < 1 || nxt_x > n || nxt_y < 1 || nxt_y > n) continue;
			if (visd[nxt_x][nxt_y]) continue;
			ins(nxt_x, nxt_y, x, y);
		}
	}
	if (!visd[dest_x][dest_y]) return false;
	
	vector<P> path; path.clear();
	int x = dest_x, y = dest_y;
	while(x>=0) {
		path.push_back(P(x, y));
		int fr_x = last[x][y].first, fr_y = last[x][y].second;
		x = fr_x; y = fr_y;
	}
	
	steps.clear();
	for(int i=(int)path.size()-1; i>0;i--)
		steps.push_back(make_pair(path[i], path[i-1]));
	
	return true;
}

void solve(P*pos, vector<pair<P, P> > &ans) {
	ans.clear();
	
	set<int> todo; todo.clear();
	for(int i=1;i<=m;i++) {
		if (pos[i].x != 1) continue;
		todo.insert(i);
	}
	
	bool occ[ran]; memset(occ, false, sizeof occ);
	for(int i=1;i<=m;i++)
		if (pos[i].x == 2) occ[pos[i].y] = true;
	while(!todo.empty()) {
		set<int>::iterator it;
		for(it = todo.begin(); it!=todo.end();it++) {
			int id = (*it);
			int todo_y = -1;
			for(int j=1;j<=n && todo_y == -1;j++)
				if (!occ[j]) todo_y = j;
			vector<pair<P, P> > steps;
			if (get_path(pos, id, 2, todo_y, steps)) {
				for(int j=0;j<steps.size(); j++)
					ans.push_back(steps[j]);
				pos[id].x = 2; pos[id].y = todo_y;
				todo.erase(it);
				occ[todo_y] = true;
				break;
			}
		}
	}
	
	int rem = m;
	while(rem > 0) {
		for(int i=1;i<=m;i++)
			if (pos[i].x != 1 || pos[i].y != i) {
				vector<pair<P, P> > steps;
				if (get_path(pos, i, 1, i, steps)) {
					for(int j=0;j<steps.size(); j++)
						ans.push_back(steps[j]);
					pos[i].x = 1; pos[i].y = i;
					rem--;
				}
			}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) scanf("%d%d", &fr[i].x, &fr[i].y);
	for(int i=1;i<=m;i++) scanf("%d%d", &to[i].x, &to[i].y);
	
	ans1.clear(); ans2.clear();
	if (n>1) {
		solve(fr, ans1);
		solve(to, ans2);
	}
	
	printf("%d\n", ans1.size() + ans2.size());
	for(int i=0;i<ans1.size();i++)
		printf("%d %d %d %d\n", ans1[i].first.x, ans1[i].first.y, ans1[i].second.x, ans1[i].second.y);
	for(int i=ans2.size()-1;i>=0;i--)
		printf("%d %d %d %d\n", ans2[i].second.x, ans2[i].second.y, ans2[i].first.x, ans2[i].first.y);
	
	return 0;
}