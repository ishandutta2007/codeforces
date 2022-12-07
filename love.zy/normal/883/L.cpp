#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<INT, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<class T>inline void printsp(T x) {print(x);putchar(' ');}

template<class T>inline void println(T x) {print(x);putchar('\n');}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}



#ifndef ONLINE_JUDGE

void debug() {cout << endl;}

template<typename T, typename... Args>void debug(T&& head, Args&&... tail) {cout << head << ' ';debug(tail...);}

#endif



#define NN 210000



int N, K, M;

set<pii> cars[NN];

set<int> pos;

set<int>::iterator it;

PQ arrival;

int x[NN];

INT ready[NN];



bool cmp(int c1, int c2, int tar) {

	if (abs(x[c1]-tar)<abs(x[c2]-tar)) return true;

	if (abs(x[c1]-tar)>abs(x[c2]-tar)) return false;

	if (ready[c1]<ready[c2]) return true;

	if (ready[c1]>ready[c2]) return false;

	return c1<c2;

}



int main() {

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	

	gn(N, K, M);

	for (int i=0; i<K; i++) {

		gn(x[i]);

		cars[x[i]].insert(pii(ready[i]=0, i));

		pos.insert(x[i]);

	}

	

	for (int i=0; i<M; i++) {

		INT t; int a, b, c=-1;

		gn(t, a, b);

		while (!arrival.empty() && arrival.top().first<=t) {

			pii p=arrival.top(); arrival.pop();

			cars[x[p.second]].insert(p);

			pos.insert(x[p.second]);

		}

		if (pos.empty()) {

			INT t1=arrival.top().first;

			while (!arrival.empty() && arrival.top().first<=t1) {

				pii p=arrival.top(); arrival.pop();

				cars[x[p.second]].insert(p);

				pos.insert(x[p.second]);

			}

		}

		it=pos.lower_bound(a);

		if (it!=pos.end()) {

			c=cars[*it].begin()->second;

		}

		if (it!=pos.begin()) {

			it--;

			int c1=cars[*it].begin()->second;

			if (c==-1 || cmp(c1, c, a)) c=c1;

		}

		

		INT take_time=max(ready[c], t)+abs(x[c]-a);

		

		printsp(c+1); println(take_time-t);

		

		cars[x[c]].erase(pii(ready[c], c));

		if (cars[x[c]].empty()) pos.erase(x[c]);

		

		x[c]=b; 

		arrival.push(pii(ready[c]=take_time+abs(b-a), c));

	}

	

	return 0;

}