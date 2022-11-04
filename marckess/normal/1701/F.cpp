// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto randis = uniform_int_distribution<int>(numeric_limits<int>::min(), numeric_limits<int>::max());

struct TreapNode{
	TreapNode *left, *right;
	int value, key, size, ex, cn;

	ll sum;
	ll izq, d_i;
	ll der, d_d;

	TreapNode(int value): left(0), right(0), value(value), key(randis(rng)), size(1), ex(0), cn(0), sum(0), izq(0), d_i(0), der(0), d_d(0) {}
};

inline int nodeSize(TreapNode* t){return t ? t->size: 0;}

inline int nodeSum(TreapNode* t){return t ? t->sum : 0;}

inline int nodeCn(TreapNode* t){return t ? t->cn : 0;}

inline void push(TreapNode* t){
	if(!t) return;
	
	if (t->izq || t->d_i) {
		int off = nodeCn(t->left);
		t->sum += t->d_i * off + t->izq;
		if(t->left) t->left->izq += t->izq, t->left->d_i += t->d_i;
		if(t->right) t->right->izq += t->d_i * (off + t->ex) + t->izq, t->right->d_i += t->d_i;
		t->izq = 0;
		t->d_i = 0;
	}
	
	if (t->der || t->d_d) {
		int off = nodeCn(t->right);
		t->sum += t->d_d * off + t->der;
		if(t->left) t->left->der += t->d_d * (off + t->ex) + t->der, t->left->d_d += t->d_d;
		if(t->right) t->right->der += t->der, t->right->d_d += t->d_d;
		t->der = 0;
		t->d_d = 0;
	}
}

inline void update(TreapNode* &t){
	if(!t) return;
	t->size = 1 + nodeSize(t->left) + nodeSize(t->right);
	t->cn = t->ex + nodeCn(t->left) + nodeCn(t->right);
}

void merge(TreapNode* &t, TreapNode* t1, TreapNode* t2){
	push(t1); push(t2);
	if(!t1) t = t2;
	else if(!t2) t = t1;
	else if(t1->key > t2->key)
		merge(t1->right, t1->right, t2), t = t1;
	else
		merge(t2->left, t1, t2->left), t = t2;
	update(t);
}

// t1: valores menores o iguales a x
// t2: valores mayores a x
void split(TreapNode* t, int x, TreapNode* &t1, TreapNode* &t2){
	if(!t)
		return void(t1 = t2 = NULL);
	push(t);
	if(x < t->value)
		split(t->left, x, t1, t->left), t2 = t;
	else
		split(t->right, x, t->right, t2), t1 = t;
	update(t);
}

int q, d;
ll res;
TreapNode *t;

ll f (ll n) {
	return n * (n - 1) / 2;
}

void main_() {
	cin >> q >> d;
	
	forr (i, 1, int(2e5))
		merge(t, t, new TreapNode(i));
	
	while (q--) {
		int x;
		cin >> x;
		
		vector<TreapNode*> v(5);
		split(t, x - d - 1, v[0], t);
		split(t, x - 1, v[1], t);
		split(t, x, v[2], t);
		split(t, x + d, v[3], v[4]);
		
		if (v[2]->ex) {
			res -= f(nodeCn(v[1]));
			res -= v[2]->sum;
			res -= f(nodeCn(v[3]));
			
			if (v[1]) v[1]->d_i = -1;
			if (v[3]) v[3]->d_d = -1;
			
			v[2]->ex = 0;
		} else {
			res += f(nodeCn(v[1]));
			res += v[2]->sum;
			res += f(nodeCn(v[3]));
			
			if (v[1]) v[1]->d_i = 1;
			if (v[3]) v[3]->d_d = 1;
			
			v[2]->ex = 1;
		}
		
		merge(t, v[0], v[1]);
		merge(t, t, v[2]);
		merge(t, t, v[3]);
		merge(t, t, v[4]);
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}