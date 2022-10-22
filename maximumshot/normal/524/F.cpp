#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

struct Queue {
	vec< pair< int, pii > > l, r;
	// {val, {mn, mx}}

	Queue() {
	
	}

	void push(int val) {
		int mn, mx;
		mn = mx = val;
		if(!l.empty()) {
			mn = min(mn, l.back().second.first);
			mx = max(mx, l.back().second.second);
		}
		l.push_back(mp(val, mp(mn, mx)));
	}

	void rebuild() {
		int val, mn, mx;
		while(!l.empty()) {
			val = l.back().first;
			l.pop_back();
			mn = mx = val;
			if(!r.empty()) {
				mn = min(mn, r.back().second.first);
				mx = max(mx, r.back().second.second);
			}	
			r.push_back(mp(val, mp(mn, mx)));
		}
	}

	void pop() {
		if(l.empty() && r.empty()) return;
		if(r.empty()) rebuild();
		r.pop_back();
	}

	int get_min() {
		int mn = +inf;
		if(!l.empty()) mn = min(mn, l.back().second.first);
		if(!r.empty()) mn = min(mn, r.back().second.first);
		return mn;
	}

	int get_max() {
		int mx = -inf;
		if(!l.empty()) mx = max(mx, l.back().second.second);
		if(!r.empty()) mx = max(mx, r.back().second.second);
		return mx;
	}
};

//  
vec< int > buildSA(const string & s) { 
	int n = (int)s.size(), q;
	vec< int > cnt(300), c(n), cn(n), p(n), pn(n);
	for(int i = 0;i < n;i++) cnt[s[i]]++;
	for(int i = 1;i < 300;i++) cnt[i] += cnt[i - 1];
	for(int i = n - 1;i >= 0;i--) p[--cnt[s[i]]] = i;
	q = 0;
	c[p[0]] = 0;
	for(int i = 1;i < n;i++) {
		if(s[p[i]] != s[p[i - 1]]) q++;
		c[p[i]] = q;
	}
	cnt.clear();
	cnt.resize(n);
	for(int k = 0;(1 << k) < n;k++) {
		for(int i = 0;i < n;i++) {
			pn[i] = p[i] - (1 << k);
			pn[i] = (pn[i] % n + n) % n;
			cnt[i] = 0;
		}
		for(int i = 0;i < n;i++) cnt[c[pn[i]]]++;
		for(int i = 1;i < n;i++) cnt[i] += cnt[i - 1];
		for(int i = n - 1;i >= 0;i--) p[--cnt[c[pn[i]]]] = pn[i];
		q = 0;
		cn[p[0]] = 0;
		for(int l1, r1, l2, r2, i = 1;i < n;i++) {
			l1 = p[i - 1], r1 = (l1 + (1 << k)) % n;
			l2 = p[i], r2 = (l2 + (1 << k)) % n;
			if(c[l1] != c[l2] || c[r1] != c[r2]) q++;
			cn[p[i]] = q;
		}
		for(int i = 0;i < n;i++) c[i] = cn[i];
	}
	return p;
}

const int LMAX = 1000100;
char buff[LMAX];

bool solve() {

	scanf("%s", &buff);

	string s = buff;

	int open, close;

	open = close = 0;

	for(auto i : s) {
		if(i == '(') open++;
		else close++;
	}

	vec< int > sa = buildSA(s);
	int res = -1;

	vec< int > pos((int)s.size());
	for(int i = 0;i < (int)s.size();i++) pos[sa[i]] = i;

	s = s + s;
	int n = (int)s.size();
	vec< int > balance(n); 

	Queue q;
	
	if(open >= close) {
		for(int d = 0, l = 0, r = 0;r + 1 < n;r++) {
			balance[r] = (r?balance[r - 1] : 0) + (s[r] == '('?1 : -1);
			q.push(balance[r]);
			if(r - l + 1 > n / 2) {
				q.pop();
				if(s[l] == '(') d--;
				else d++;
				l++;
			}
			if(r - l + 1 < n / 2) continue;
			// r - l + 1 == n / 2
			if(q.get_min() + d >= 0 && (res == -1 || pos[res] > pos[l])) res = l;
		}
	}else { // open < close
		for(int d = 0, l = n - 1, r = n - 1;l >= 0;l--) {
			balance[l] = (l + 1 < n?balance[l + 1] : 0) + (s[l] == ')'?1 : -1);
			q.push(balance[l]);
			if(r - l + 1 > n / 2) {
				q.pop();
				if(s[r] == ')') d--;
				else d++;
				r--;
			}
			if(r - l + 1 < n / 2) continue;
			// r - l + 1 == n / 2
			if(l >= n / 2) continue;
			if(q.get_min() + d >= 0 && (res == -1 || pos[res] > pos[l])) res = l;			
		}
	}

	for(int i = 0;i < close - open;i++) printf("(");
	for(int i = res;i < n / 2;i++) printf("%c", s[i]);
	for(int i = 0;i < res;i++) printf("%c", s[i]);
	for(int i = 0;i < open - close;i++) printf(")");

	printf("\n");

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}