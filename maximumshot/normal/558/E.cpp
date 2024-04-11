#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
	os.precision(10);
	os << fixed;
	os << a.first;
	os << ' ';
	os << a.second;
	os << '\n';
	return os;
}

const int ALPHSIZE = 26;

void update(vec< pair<int, int> > & mas) {
	vec< pair<int, int> > ans;
	for(int i(0);i < (int)mas.size();i++) {
		int j = i, c = 0;
		while(j < (int)mas.size() && mas[i].first == mas[j].first) c += mas[j].second, j++; j--;
		ans.push_back(mp(mas[i].first, c));
		i = j;
	}
	mas = ans;
}

void insertUp(vec< pair< int, int> > & mas, vec< int > & c, int needsize) {
	int nowsize = 0;
	for(auto i : mas) nowsize += i.second;
	int symb = 0;
	while(nowsize < needsize) {
		while(c[symb] == 0) symb++;
		int delt = min(needsize - nowsize, c[symb]);
		nowsize += delt;
		mas.push_back(mp(symb, delt));
		c[symb] -= delt;
	}
}

void insertDown(vec< pair< int, int> > & mas, vec< int > & c, int needsize) {
	int nowsize = 0;
	for(auto i : mas) nowsize += i.second;
	int symb = ALPHSIZE - 1;
	while(nowsize < needsize) {
		while(c[symb] == 0) symb--;
		int delt = min(needsize - nowsize, c[symb]);
		nowsize += delt;
		mas.push_back(mp(symb, delt));
		c[symb] -= delt;
	}
}

int n, q;
string s;

void read() {
	char buffer[100100];
	scanf("%s", &buffer);
	s = buffer;
}

struct block {
	vec< int > cnt;
	vec< pair<int, int > > mas;
	block() {
		cnt.clear();
		mas.clear();
	}
};

void recovery(block & a) {
	a.cnt.clear();
	a.cnt.resize(ALPHSIZE, 0);
	for(auto i : a.mas) {
		a.cnt[i.first] += i.second;
	}
}

vec< block > p;
int bsize;

void build() {
	bsize = ceil(sqrt(double(n)));
	p.resize((n - 1) / bsize + 1);
	for(int i(0);i < n;i++) {
		p[i / bsize].mas.push_back(mp(s[i] - 'a', 1));
	}
	for(auto & i : p) {
		update(i.mas);
		recovery(i);
	}
}

void Generate(const vec< pair< int, int> > & mas, vec< pair<int, int> > & p1, vec< pair< int, int> > & p2, int x, int BlockId) {
	// [<= x] [> x]
	
	int sz = (int)mas.size();
	for(int ql = BlockId * bsize, qr, i = 0;i < sz;i++) {
		int symb = mas[i].first;
		int c = mas[i].second;
		qr = ql + c - 1;
		if(qr <= x) p1.push_back(mas[i]);
		else if(ql > x) p2.push_back(mas[i]);
		else {
			p1.push_back(mp(symb, x - ql + 1));
			p2.push_back(mp(symb, qr - x));
		}

		ql += c;
	}
} 

void SortUp(int l, int r) {
	vec< int > C(ALPHSIZE, 0);
	int lid = l / bsize;
	int rid = r / bsize;
	for(int i(lid + 1);i < rid;i++) for(int j(0);j < 26;j++) 
		C[j] += p[i].cnt[j];
	
	vec< pair< int, int > > p1, p2, p3;

	if(lid == rid) {
		int sz = (int)p[lid].mas.size();
		for(int ql = lid * bsize, qr, i = 0;i < sz;i++) {
			int symb = p[lid].mas[i].first;
			int c = p[lid].mas[i].second;
			qr = ql + c - 1;
			if(qr < l) p1.push_back(p[lid].mas[i]);
			else if(ql > r) p3.push_back(p[lid].mas[i]);
			else if(l <= ql && qr <= r) p2.push_back(p[lid].mas[i]);
			else if(ql < l && r < qr) {
				p1.push_back(mp(symb, l - ql));
				p2.push_back(mp(symb, r - l + 1));
				p3.push_back(mp(symb, qr - r));
			}else if(ql < l && qr >= l && qr <= r) {
				p1.push_back(mp(symb, l - ql));
				p2.push_back(mp(symb, qr - l + 1));
			}else if(ql >= l && ql <= r && qr > r) {
				p2.push_back(mp(symb, r - ql + 1));
				p3.push_back(mp(symb, qr - r));
			}

			ql += c;
		}

		p[lid].mas.clear();
		sort(ALL(p2));
		
		for(auto i : p1) p[lid].mas.push_back(i);
		for(auto i : p2) p[lid].mas.push_back(i);
		for(auto i : p3) p[lid].mas.push_back(i);

		update(p[lid].mas);
		recovery(p[lid]);
	}else {
		Generate(p[lid].mas, p1, p2, l - 1, lid);
		Generate(p[rid].mas, p2, p3, r, rid);

		int ls, rs;
		ls = rs = 0;
		
		for(auto i : p[lid].mas) ls += i.second;
		for(auto i : p[rid].mas) rs += i.second;

		p[lid].mas.clear();
		p[rid].mas.clear();

		for(auto i : p2) C[i.first] += i.second;

		// lid
		for(auto i : p1) p[lid].mas.push_back(i);
		insertUp(p[lid].mas, C, ls);
		update(p[lid].mas);
		recovery(p[lid]);
	
		for(int i(lid + 1);i < rid;i++) {
			p[i].mas.clear();
			insertUp(p[i].mas, C, bsize);
			update(p[i].mas);
			recovery(p[i]);
		}

		// rid
		for(auto i : p3) rs -= i.second;
		insertUp(p[rid].mas, C, rs);
		for(auto i : p3) p[rid].mas.push_back(i);
		update(p[rid].mas);
		recovery(p[rid]);
	}
}

void SortDown(int l, int r) {
	vec< int > C(ALPHSIZE, 0);
	int lid = l / bsize;
	int rid = r / bsize;
	for(int i(lid + 1);i < rid;i++) for(int j(0);j < 26;j++) 
		C[j] += p[i].cnt[j];
	
	vec< pair< int, int > > p1, p2, p3;

	if(lid == rid) {
		int sz = (int)p[lid].mas.size();
		for(int ql = lid * bsize, qr, i = 0;i < sz;i++) {
			int symb = p[lid].mas[i].first;
			int c = p[lid].mas[i].second;
			qr = ql + c - 1;
			if(qr < l) p1.push_back(p[lid].mas[i]);
			else if(ql > r) p3.push_back(p[lid].mas[i]);
			else if(l <= ql && qr <= r) p2.push_back(p[lid].mas[i]);
			else if(ql < l && r < qr) {
				p1.push_back(mp(symb, l - ql));
				p2.push_back(mp(symb, r - l + 1));
				p3.push_back(mp(symb, qr - r));
			}else if(ql < l && qr >= l && qr <= r) {
				p1.push_back(mp(symb, l - ql));
				p2.push_back(mp(symb, qr - l + 1));
			}else if(ql >= l && ql <= r && qr > r) {
				p2.push_back(mp(symb, r - ql + 1));
				p3.push_back(mp(symb, qr - r));
			}

			ql += c;
		}

		p[lid].mas.clear();
		sort(ALL(p2));
		reverse(ALL(p2));

		for(auto i : p1) p[lid].mas.push_back(i);
		for(auto i : p2) p[lid].mas.push_back(i);
		for(auto i : p3) p[lid].mas.push_back(i);

		update(p[lid].mas);
		recovery(p[lid]);
	}else {
		Generate(p[lid].mas, p1, p2, l - 1, lid);
		Generate(p[rid].mas, p2, p3, r, rid);

		int ls, rs;
		ls = rs = 0;
		
		for(auto i : p[lid].mas) ls += i.second;
		for(auto i : p[rid].mas) rs += i.second;

		p[lid].mas.clear();
		p[rid].mas.clear();

		for(auto i : p2) C[i.first] += i.second;

		// lid
		for(auto i : p1) p[lid].mas.push_back(i);
		insertDown(p[lid].mas, C, ls);
		update(p[lid].mas);
		recovery(p[lid]);
	
		for(int i(lid + 1);i < rid;i++) {
			p[i].mas.clear();
			insertDown(p[i].mas, C, bsize);
			update(p[i].mas);
			recovery(p[i]);
		}

		// rid
		for(auto i : p3) rs -= i.second;
		insertDown(p[rid].mas, C, rs);
		for(auto i : p3) p[rid].mas.push_back(i);
		update(p[rid].mas);
		recovery(p[rid]);
	}
}

void print() {
	for(auto i : p) 
		for(auto j : i.mas) 
			for(int z(0);z < j.second;z++) 
				cout << char(j.first + 'a');
	cout << "\n";
}

bool solve()
{		
	scanf("%d %d", &n, &q);
	read();
	build();

	int l, r, t;

	while(q--) {
		scanf("%d %d %d", &l, &r, &t);
		l--, r--;
		if(t == 1) {
			SortUp(l, r);
		}else {
			SortDown(l, r);
		}
	}

	print();

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}