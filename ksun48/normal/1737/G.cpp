#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

mt19937 mt(48);

struct node {
	int sz;
	ll v, p, lazy;
	node *l, *r;
	node(ll _v): sz(1), v(_v), p(mt()), lazy(0), l(nullptr), r(nullptr) {}
};

void push(node* t){
	if(!t) return;
	// unlazy a node, gives correct values of sum, lazy -> 0
	if(t->lazy){
		if(t->l) t->l->lazy += t->lazy;
		if(t->r) t->r->lazy += t->lazy;
		t->v += t->lazy;
		t->lazy = 0;
	}
}


int sz(node* t){
	push(t);
	return (t == nullptr ? 0 : t->sz);
}
ll val(node* t){
	push(t);
	return (t == nullptr ? 0 : t->v);
}

ll max(node* t){
	push(t);
	if(t->r) return max(t->r);
	return t->v;
}
ll min(node* t){
	push(t);
	if(t->l) return min(t->l);
	return t->v;
}
void upd(node* t){ // computes fully correct values of sum, sz
	if(!t) return;
	t->sz = 1+sz(t->l)+sz(t->r);
}
void split_cnt(node *t, node *&l, node *&r, ll k){ // splits into [0,k-1] and [k,?]
	push(t);
	if(t == nullptr){
		l = nullptr;
		r = nullptr;
	} else if(sz(t->l) < k){
		split_cnt(t->r,t->r,r,k-sz(t->l)-1);
		l = t;
	} else {
		split_cnt(t->l,l,t->l,k);
		r = t;
	}
	upd(t);
}
void split_v(node *t, node *&l, node *&r, ll v){ // splits into < v and >= v
	push(t);
	if(t == nullptr){
		l = nullptr;
		r = nullptr;
	} else if(t->v < v){
		split_v(t->r,t->r,r,v);
		l = t;
	} else {
		split_v(t->l,l,t->l,v);
		r = t;
	}
	upd(t);
}
void merge(node *&t, node *l, node *r){
	push(l);
	push(r);
	if(l == nullptr){
		t = r;
	} else if(r == nullptr){
		t = l;
	} else if(l->p < r->p){
		merge(l->r, l->r,r);
		t = l;	
	} else {
		merge(r->l,l,r->l);
		t = r;
	}
	upd(t);
}

ll kth(node* t, ll k){
	push(t);
	int lsz = sz(t->l);
	if(lsz == k){
		return t->v;
	} else if(lsz < k){
		return kth(t->r, k - lsz - 1);
	} else if(lsz > k){
		return kth(t->l, k);
	} else assert(false);
}

int nless(node* t, ll v){
	if(!t) return 0;
	push(t);
	if(t->v < v){
		return sz(t->l) + 1 + nless(t->r, v);
	} else {
		return nless(t->l, v);
	}
}

void pt(node *r){
	if(r == nullptr) return;
	push(r);
	pt(r->l);
	cerr << r->v << ' ';
	pt(r->r);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll N;
	ll D;
	int Q;
	cin >> N >> D >> Q;
	vector<ll> A(N);
	for(ll& x : A) cin >> x;
	string mov;
	cin >> mov;
	vector<pair<ll, int> > queries(Q);
	for(int i = 0; i < Q; i++){
		cin >> queries[i].first >> queries[i].second;
		queries[i].second--;
	}
	vector<int> qord(Q);
	for(int i = 0; i < Q; i++) qord[i] = i;
	sort(qord.begin(), qord.end(), [&](int x, int y) { return queries[x] < queries[y]; });

	vector<ll> answer(Q, -1);
	vector<ll> immovable;
	ll diff = 0;
	vector<ll> real_pos;
	for(int i = 0; i < N; i++){
		if(mov[i] == '0'){
			immovable.push_back(A[i]);
			diff++;
		} else {
			real_pos.push_back(A[i] - diff);
		}
	}

	int dancer_cnt = 0;

	node* line = new node(real_pos[dancer_cnt]);
	dancer_cnt++;
	node* extras = nullptr;
	for(int d = dancer_cnt; d < (int)real_pos.size(); d++){
		node* r = new node(real_pos[d]);
		merge(extras, extras, r);
	}

	int qidx = 0;
	ll ctime = 0;
	while(qidx < Q){
		int q = qord[qidx];
		ll qtime = queries[q].first;
		if(ctime == qtime){
			// answer query;
			node* merged;
			merge(merged, line, extras);
			// pt(merged); cerr << '\n';
			int k = queries[q].second;
			// for(ll r : immovable){
			// 	cerr << r << ' ';
			// }
			// cerr << '\n';
			// cerr << "idx " << queries[q].second << '\n';
			if(immovable.empty()){
				answer[q] = kth(merged, k);
			} else {
				int s = -1;
				int e = (int)immovable.size();
				while(s + 1 < e){
					int m = (s + e) / 2;
					int less = nless(merged, immovable[m] - m); 
					if(less + m == k){
						answer[q] = immovable[m];
						break;
					} else if(less + m > k){
						e = m;
					} else if(less + m < k){
						s = m;
					} else assert(false);
				}
				if(answer[q] == -1){
					answer[q] = kth(merged, k - e) + e;
				}
			}
			split_cnt(merged, line, extras, dancer_cnt);
			qidx++;
			continue;
		}

		ll next_dancer = ll(4e18);
		if(dancer_cnt < (int)real_pos.size()){
			next_dancer = real_pos[dancer_cnt];
		}

		ll inc = dancer_cnt + (D-1);

		ll L = min(line);
		ll R = max(line);
		if(L + inc >= next_dancer){
			node* dancer;
			split_cnt(extras, dancer, extras, 1);
			merge(line, line, dancer);
			dancer_cnt++;
			continue;
		}
		if(qtime - ctime >= dancer_cnt && R + inc < next_dancer){
			// can do whole intervals;
			ll nfull = min((qtime - ctime) / dancer_cnt, (next_dancer - 1 - R) / inc);
			line->lazy += nfull * inc;
			ctime += nfull * dancer_cnt;
			continue;
		}
		{
			node *b, *c;
			split_v(line, b, c, next_dancer - inc);
			int bsz = sz(b);
			assert(bsz >= 1);
			merge(line, b, c);
			ll nmove = min(ll(bsz), qtime - ctime);
			split_cnt(line, b, c, nmove);
			assert(sz(b) >= 1);
			b->lazy += inc;
			merge(line, c, b);
			ctime += nmove;
			continue;
		}
	}
	for(int i = 0; i < Q; i++){
		cout << answer[i] << '\n';
	}
}