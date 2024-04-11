#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;

struct Punto {
	ll x, y;

	Punto operator - (Punto ot) {
		return {x - ot.x, y - ot.y};
	}

	Punto operator * (int s) {
		return {x * s, y * s};
	}

	void leer () {
		cin >> x >> y;
	}

	ll abs () {
		return x * x + y * y;
	}

	void impr () {
		cout << x << " " << y << endl;
	}
};

struct Tree {
	Tree *izq, *der;
	Punto p;
	int ind, s;

	Tree () : ind(-1) {}
	Tree (Tree *_izq, Tree *_der, Punto _p, int _ind, int _s) :
		izq(_izq), der(_der), p(_p), ind(_ind), s(_s) {}
};

ll dist (Tree *a, int sa, Tree *b, int sb) {
	return (a->p * sa - b->p * sb).abs();
}

int n, res[MX];
int p1[12] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
int p2[12] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
int p3[12] = {2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0 ,0};
int s1[12] = {1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1};
int s2[12] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1}; 
Punto p[MX];

queue<Tree*> q;
Tree *obtTree () {
	for (int i = 0; i < n; i++)
		q.push(new Tree(0, 0, p[i], i, 1));

	while (q.size() > 2) {
		Tree *t[3];
		t[0] = q.front(); q.pop();
		t[1] = q.front(); q.pop();
		t[2] = q.front(); q.pop();

		Tree *res[3];
		res[0] = t[0], res[1] = t[1], res[2] = t[2];
		int sg[3] = {1};
		ll mn = 1e18;

		for (int l = 0; l < 12; l++) {
			ll d = dist(t[p1[l]], s1[l], t[p2[l]], s2[l]);

			if (d < mn) {
				mn = d;
				res[0] = t[p1[l]];
				res[1] = t[p2[l]];
				res[2] = t[p3[l]];
				sg[0] = s1[l];
				sg[1] = s2[l];
			}
		}

		res[0]->s = sg[0];
		res[1]->s = -sg[1];

		q.push(res[2]);
		q.push(new Tree(res[0], res[1], res[0]->p * sg[0] - res[1]->p * sg[1], -1, 1));
	}

	Tree *t[2];
	t[0] = q.front(); q.pop();
	t[1] = q.front(); q.pop();

	Tree *res[3];
	res[0] = t[0], res[1] = t[1];
	int sg[2] = {1};
	ll mn = 1e18;

	for (int l = 0; l < 4; l++) {
		ll d = dist(t[p1[l]], s1[l], t[p2[l]], s2[l]);
		if (d < mn) {
			mn = d;
			res[0] = t[p1[l]];
			res[1] = t[p2[l]];
			sg[0] = s1[l];
			sg[1] = s2[l];
		}
	}

	res[0]->s = sg[0];
	res[1]->s = -sg[1];

	return new Tree(res[0], res[1], res[0]->p * sg[0] - res[1]->p * sg[1], -1, 1);
}

void obtRes (Tree *t, int s) {
    if (t->ind != -1) {
		res[t->ind] = s * t->s;
		return;
	}

	obtRes(t->izq, s * t->s);
	obtRes(t->der, s * t->s);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		p[i].leer();

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	//cout << sqrt(obtTree()->p.abs()) << endl;
	obtRes(obtTree(), 1);

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}