#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

/* Fast Integer IO */
template<typename T> inline T read(T &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<typename T, typename... Args> inline void read(T &x, Args& ...args){
	read(x); read(args...);
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define MAXN 200005

int N;
struct Z{ int x, v, idx; } A[MAXN];

lld bit[MAXN]; int cbit[MAXN];
void add(int n, int v){ for (;n<=N;n+=n&-n) bit[n] += v, cbit[n]++; }
void get(int s, int e, lld &sum, int &cnt){
	sum = cnt = 0;
	for (;e;e^=e&-e) sum += bit[e], cnt += cbit[e];
	for (s--;s;s^=s&-s) sum -= bit[s], cnt -= cbit[s];
}

int main()
{
	read(N);
	for (int i=1;i<=N;i++) read(A[i].x);
	for (int i=1;i<=N;i++) read(A[i].v);
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.x < b.x;
	});
	for (int i=1;i<=N;i++) A[i].idx = i;
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.v != b.v ? a.v > b.v : a.x > b.x;
	});
	lld ans = 0;
	for (int i=1;i<=N;i++){
		add(A[i].idx, A[i].x);
		lld sum = 0; int cnt = 0;
		get(A[i].idx+1, N, sum, cnt);
		ans += sum-(lld)A[i].x*cnt;
	}
	write(ans); puts("");
}