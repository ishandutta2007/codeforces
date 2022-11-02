#include <bits/stdc++.h>
using namespace std;

#define pb push_back
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

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define MAXN 1003

int N;
int X[MAXN], Y[MAXN];

template <typename T>
T operator + (const T &a, const T &b){
	T ret = a;
	for (auto t: b) ret.pb(t);
	return ret;
}

void proc(vector <int> arr[2][2])
{
	vector <int> ans;
	if (sz(arr[0][0])+sz(arr[1][1]) == N) ans = arr[0][0];
	else if (sz(arr[0][1])+sz(arr[1][0]) == N) ans = arr[0][1];
	else ans = arr[0][0]+arr[1][1];
	write(sz(ans)); puts("");
	for (int t: ans) write(t), putchar(' '); puts("");
}

int main()
{
	read(N);
	for (int i=1;i<=N;i++) read(X[i], Y[i]), X[i] += 1e6, Y[i] += 1e6;
	for (;;){
		vector <int> arr[2][2];
		for (int i=1;i<=N;i++)
			arr[X[i]&1][Y[i]&1].pb(i);
		int mx = 0;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) mx = max(mx, sz(arr[i][j]));
		if (mx < N){ proc(arr); break; }
		for (int i=1;i<=N;i++){
			if (X[i]&1) X[i]++;
			if (Y[i]&1) Y[i]++;
			X[i] >>= 1, Y[i] >>= 1;
		}
	}
}