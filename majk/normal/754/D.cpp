/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Majk
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
constexpr int MOD = 1000000007;

typedef std::pair<int,int> pii;
typedef long long ll;

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template <typename K, typename V> struct avlnode {
	avlnode(K k, V v) : l(0),r(0),h(1),s(1),k(k),v(v) {}
	~avlnode() { delete l; delete r; }
	avlnode<K,V> *l,*r;int h,s;K k;V v;
	int size() const { return s; }
	void u() { s=(l?l->s:0)+(r?r->s:0)+1; h=max(l?l->h:0,r?r->h:0)+1; }
	avlnode<K,V>*rr() {auto x = l; l = x->r; u(); x->r = this; x->u(); return x; }
	avlnode<K,V>*lr() {auto y = r; r = y->l; u(); y->l = this; y->u(); return y; }
	avlnode<K,V>*insert(K k, V v) {
		if (k<this->k) l=l?l->insert(k,v):new avlnode<K,V>(k,v);
		else r=r?r->insert(k,v):new avlnode<K,V>(k,v);
		return balance();
	}
	int getBalance() const { return (l?l->h:0) - (r?r->h:0); }
	avlnode<K,V>* get(K k) {
		if (k<this->k) { return l ? l->get(k) : nullptr; }
		else if (k>this->k) { return r ? r->get(k) : nullptr; }
		else { return this; }
	};
	avlnode<K,V>* remove(K k) {
		if (k<this->k) { if(l) l = l->remove(k); else return this; }
		else if (k>this->k) { if (r) r = r->remove(k); else return this; }
		else if (!l) { avlnode<K,V>*t = r; r = nullptr; delete this; return t; }
		else if (!r) { avlnode<K,V>*t = l; l = nullptr; delete this; return t; }
		else { avlnode<K,V>* q = l; while (q->r) { q = q->r; } this->k = q->k; this->v = q->v; l = l->remove(this->k); }
		return balance();
	};
	avlnode<K,V>* balance() {
		int b = getBalance();
		if (b > 1) { if (l->getBalance() >= 0) return rr(); else { l = l->lr(); return rr(); } }
		if (b < -1) { if (r->getBalance() > 0) { r=r->rr(); return lr(); } else { return lr(); } }
		u(); return this;
	};
	template<typename T> void foreach(T f) {if(l){l->foreach(f);}f(k,v);if(r){r->foreach(f);}}
	avlnode<K,V>* at(int c) {if (l) {if (l->s > c) return l->at(c); else c -= l->s;} return c ? r->at(c-1) : this; }
	avlnode<K,V>* merge(avlnode<K,V> *n) {auto q = this; n->foreach([&q](K k,V v){ q=q->insert(k,v); }); return q; }
};
template<typename K,typename V>ostream& operator<<(ostream &os, const avlnode<K,V>& t) {os<<'<';if (t.l){os<<t.l<<',';}os<<'('<<t.k<<','<<t.v<<')';if(t.r){os<<','<<t.r;}os<<'>';return os;}

template<typename K, typename V> struct avl {
	avl() : r(0) {}
	~avl() { delete r; }
	avlnode<K,V>* get(K k) { return r?r->get(k):0; };
	void insert(K k, V v) { r=r?r->insert(k,v):new avlnode<K,V>(k,v); };
	void remove(K k) { r=r?r->remove(k):r; }
	avlnode<K,V>* at(int c) { if (!r||r->s<c||c<0) return 0; else return r->at(c); };
	int size() const { return r?r->s:0; }
	template<typename T> void foreach(T f) {if(r)r->foreach(f);}
	avlnode<K,V> *r;
};
#include <set>

// static const int C = 49999;

class TaskD {
public:
	void solve(istream& cin, ostream& cout) {
		/*
		avl<int,int> X;
		for (int i = 0; i < C; ++i) {
			X.insert(i, 2 * i);
		}

		for (int j = 15; j < 26; ++j) {
			ll f = j*j*j + 18*j*j + 12*j + 33;
			f = 1 + (f % (C-1));
			for (int i = 1; i < C; i += 4) {
				//cerr << "rem " << i << endl;
					X.remove(f * i % C);
			}
			cerr << "Rem " << X.r->h << ' ' << X.r->s << endl;

			for (int i = 1; i < C; i += 4) {
				X.insert(f * i % C, 2 * (f * i % C));
			}
			cerr << "Add " << X.r->h << ' ' << X.r->s << endl;

			int error = 0;
			for (int i = 0; i < C; ++i) {
				auto f = X.get(i);
				if (f && 2*i != f->v) {
					cerr << "Err " << i << ' ' << 2*i << ' ' << f->v << endl;
					error += abs(2*i - f->v);
				}
			}

			int cur = 0;
			X.foreach([&](int k, int v) mutable { if (cur == -1) return; else if (cur != k) { cerr << "Fail on " << cur << ' ' << k << endl; cur = -1; } else ++cur; });
			cerr << "Err " << error << endl;
		}

		for (int i = 0; i < 49999; ++i) {
			auto at = X.at(i);
			if (at->k != i) cerr << "at " << at->k << ' ' << i << endl;
		}
		cerr << "At done" << endl;*/
		//cout << X.k << ' ' << X.l << ' ' << X.r << endl;
		//cout << X.at(0)->k << ' ' << X.at(1)->k << endl;


		int N, K; cin >> N >> K;
		vector<pii> I(2*N);
		vector<int> L(N);
		for (int i = 0; i < N; ++i) {
			int l,r; cin >> l >> r;
			L[i] = l;
			I[2*i] = {l, -i-1};
			I[2*i+1] = {r, i+1};
		}

		sort(I.begin(), I.end());
		ll bestLen = 0;
		ll bestEnd = 0;
		avl<pii,int> V;
		for (int i = 0; i < 2*N; ++i) {
			if (I[i].y < 0) {
				V.insert(I[i], 0);
			} else {
				if (V.size() >= K) {
					ll curLen = 1 + I[i].x - V.at(K-1)->k.x;
					if (curLen > bestLen) {
						bestLen = curLen;
						bestEnd = I[i].x;
					}
				}
				V.remove({L[I[i].y-1], -I[i].y});
			}
		}

		cout << bestLen << endl;
		if (bestLen == 0) {
			for (int i = 1; i <= K; ++i) {
				cout << i << ' ';
			}
			cout << endl;
			return;
		}

		avl<pii,int> W;
		for (int i = 0; i < 2*N; ++i) {
			if (I[i].y < 0) {
				W.insert(I[i], 0);
			} else {
				if (bestEnd == I[i].x) {
					vector<int> R;
					W.foreach([&](pii k, int v) { if (R.size() < K) R.push_back(-k.y);});
					cout << R << endl;
					return;
				}
				W.remove({L[I[i].y-1], -I[i].y});
			}
		}
		cout << bestLen << endl << bestEnd << endl;


	}
};


int main() {
	ios_base::sync_with_stdio(false);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}