#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <istream>
#include <string>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)5e5 + 10;

char FIRST = '`';
int64 BASE = 37;
int64 MOD = 1000000093LL;
string f = "";
vector<int64> _hash;
vector<int64> _base;
int sz;

int64 getHash(int b, int e){
	int64 ans = _hash[e + 1] - _hash[b] * _base[e - b + 1] % MOD;
	return (ans % MOD + MOD) % MOD;
}

bool equal(int b1, int b2, int size){
	return 		max(b1, b2) + size - 1 < sz
		&& 	getHash(b1, b1 + size - 1) == getHash(b2, b2 + size - 1)
		&& f[b1] == f[b2];
}

bool compare(int a, int b){
	if (f[a] != f[b]) return f[a] < f[b];
	int lo = 1, hi = sz - max(a, b) + 1;
	while (lo + 1 < hi){
		int mid = (lo + hi) >> 1;
		if (equal(a, b, mid)) lo = mid;
		else hi = mid;
	}
	if (hi == sz - max(a, b) + 1)
		return a > b;
	return f[a + lo] < f[b + lo];
}

void __assert(bool v){
//		while (!v);
	assert(v);
}

void inside(int x, int b, int e){
	__assert(b <= x && x <= e);
}

char tmp[200100];
int ans[500100];

struct query{
	int p, v, sg, i;
	bool operator <(const query &a){
		return p < a.p;
	}
};

int BIT[MAXN];

int read(int idx){
	if (idx < 0) return 0;
	int ans = BIT[0];
	while (idx){
		ans += BIT[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int idx){
	if (idx < 0) return;
	if (!idx) BIT[0]++;
	else{
		while (idx < MAXN){
			BIT[idx]++;
			idx += idx & -idx;
		}
	}
}

vi makesa(string s)
{
	int i, j, len, na;
	int n = (int)s.length();
	na = (n < 256 ? 256 : n);

	vi top(na);
	vi sa(n), rank(n), tmp(n);

	for(i = 0; i < n ; i++) top[rank[i] = s[i] & 0xff]++;
	for(i = 1; i < na; i++) top[i] += top[i - 1];
	for(i = 0; i < n ; i++) sa[--top[rank[i]]] = i;
	for(len = 1; len < n; len <<= 1)
	{
		for(i = 0; i < n; i++)
		{
			j = sa[i] - len; if(j < 0) j += n;
			tmp[top[rank[j]]++] = j;
		}
		sa[tmp[top[0] = 0]] = j = 0;
		for(i = 1; i < n; i++)
		{
			if(rank[tmp[i]] != rank[tmp[i - 1]] ||
				rank[tmp[i] + len] != rank[tmp[i - 1] + len])
				top[++j] = i;
			sa[tmp[i]] = j;
		}
		for (int i = 0; i < n; ++i){
			rank[i] = sa[i];
			sa[i] = tmp[i];
		}
		if(j >= n - 1) break;
	}
	return sa;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	vector<pii> T(n);

	for (int i = 0; i < n; ++i){
		scanf("%s", tmp);
		string s = (string)tmp;

		T[i] = MP(f.size(), s.size());
		f += s;
		f += FIRST;
	}

	sz = (int)f.size();
//	DB(sz);

	//	cout << f << endl;

	_hash = vector<int64>(sz + 1);
	_base = vector<int64>(sz + 1);
	_base[0] = 1;

	for (int i = 0; i < sz; ++i){
		_hash[i + 1] = (_hash[i] * BASE + f[i] - FIRST + 1) % MOD;
		_base[i + 1] = _base[i] * BASE % MOD;
	}

	vector<int> sa(sz), inv(sz);

	sa = makesa(f);

	for (int i = 0; i < sz; ++i) inv[sa[i]] = i;

	vector<query> VQ;

	for (int i = 0; i < q; ++i){

		int LE, RI, v;
		scanf("%d%d%d", &LE, &RI, &v);

		LE = T[LE - 1].first;
		RI = T[RI - 1].first + T[RI - 1].second - 1;

		int lo = inv[T[v - 1].first], hi = sz;

		while (lo + 1 < hi){
			int mid = (lo + hi) >> 1;

			if (equal(sa[mid], T[v - 1].first, T[v - 1].second)) lo = mid;
			else hi = mid;
		}

		int p2 = lo;

		lo = -1, hi = inv[T[v - 1].first];
		while (lo + 1 < hi){
			int mid = (lo + hi) >> 1;

			if (equal(sa[mid], T[v - 1].first, T[v - 1].second)) hi = mid;
			else lo = mid;
		}

		int p1 = hi;
		query qcur;
		qcur.p = p2, qcur.v = RI, qcur.sg = 1, qcur.i = i;				VQ.push_back(qcur);
		qcur.p = p1 - 1, qcur.v = RI, qcur.sg = -1, qcur.i = i;			VQ.push_back(qcur);
		qcur.p = p2, qcur.v = LE - 1, qcur.sg = -1, qcur.i = i;			VQ.push_back(qcur);
		qcur.p = p1 - 1, qcur.v = LE - 1, qcur.sg = 1, qcur.i = i;		VQ.push_back(qcur);
	}

	sort(VQ.begin(), VQ.end());
	int c = 0; while (c < (int)VQ.size() && VQ[c].p == -1) ++c;
	for (int i = 0; i < sz; ++i){
		update(sa[i]);
		for (;c < (int)VQ.size() && VQ[c].p <= i; ++c){
			ans[VQ[c].i] += VQ[c].sg * read(VQ[c].v);
		}
	}

	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);

	return 0;
}