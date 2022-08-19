#include <bits/stdc++.h>
using namespace std;

int k;

struct node {
	node* c[2];
};

node* trie;

void ins(int r){
	node* f = trie;
	for(int j = k-1; j >= 0; j--){
		if(!f->c[1 & (r >> j)]){
			f->c[1 & (r >> j)] = new node();
			f->c[1 & (r >> j)]->c[0] = f->c[1 & (r >> j)]->c[1] = nullptr;
		}
		f = f->c[1 & (r >> j)];
	}
}

vector<vector<int> > ans;
void solve(node* l, node* r, int st, int x, int d, int diff){
	if(d == k){
		ans[st][x] = min(ans[st][x], diff);
	} else {
		for(int j = 0; j < 2; j++){
			if(l->c[1^j] && r->c[0^j]){
				solve(l->c[1^j], r->c[0^j], st, x ^ (j << (k-1-d)), d+1, diff - (1 << (k-1-d)));
				continue;
			}
			if(l->c[1^j] && r->c[1^j]){
				solve(l->c[1^j], r->c[1^j], st, x ^ (j << (k-1-d)), d+1, diff);
				continue;
			}
			if(l->c[0^j] && r->c[0^j]){
				solve(l->c[0^j], r->c[0^j], st, x ^ (j << (k-1-d)), d+1, diff);
				continue;
			}
			if(l->c[0^j] && r->c[1^j]){
				solve(l->c[0^j], r->c[1^j], st, x ^ (j << (k-1-d)), d+1, diff + (1 << (k-1-d)));
				continue;
			}
		}
	}
}

void tr(node* v, int r, int d){
	if(v->c[0] && v->c[1]){
		solve(v->c[0], v->c[1], d, 0, d+1, (1 << (k-1-d)));
		solve(v->c[1], v->c[0], d, (1 << (k-1-d)), d+1, (1 << (k-1-d)));
	}
	if(v->c[0]) tr(v->c[0], 2*r+0, d+1);
	if(v->c[1]) tr(v->c[1], 2*r+1, d+1);
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	trie = new node();
	trie->c[0] = trie->c[1] = nullptr;
	int n;
	cin >> n >> k;
	ans.assign(k, vector<int>(1 << k, int(1e8)));
	vector<int> a(n);
	for(int& x : a) cin >> x;
	sort(a.begin(), a.end());
	for(int x : a) ins(x);
	assert(trie != nullptr);
	tr(trie, 0, 0);
	for(int i = 0; i < (1 << k); i++){
		int best = int(1e8);
		for(int j = 0; j < k; j++){
			best = min(best, ans[j][i % (1 << (k - j))]);
		}
		cout << best << ' ';
	}
	cout << '\n';
}