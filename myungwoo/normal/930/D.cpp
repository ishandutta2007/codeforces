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

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define MAXN 100005

int N;
struct Z{
	int x, y;
} A[MAXN];

lld proc()
{
	vector <Z> arr;
	for (int i=1;i<=N;i++) if (A[i].x+A[i].y&1) arr.pb({A[i].x+A[i].y, A[i].x-A[i].y});
	sort(all(arr), [](const Z &a, const Z &b){
		return a.x < b.x;
	});
	int n = sz(arr);
	struct RANGE{
		int la, lb; int ra, rb;
	};
	vector <RANGE> box(n);
	int mn = 2e9, mx = -2e9;
	for (int i=0;i<n;i++){
		mn = min(mn, arr[i].y);
		mx = max(mx, arr[i].y);
		box[i].la = mn, box[i].lb = mx;
	}
	mn = 2e9, mx = -2e9;
	for (int i=n;i--;){
		mn = min(mn, arr[i].y);
		mx = max(mx, arr[i].y);
		if (i > 0) box[i-1].ra = mn, box[i-1].rb = mx;
	}
	lld ret = 0;
	for (int i=0;i+1<n;i++){
		int l = max(box[i].la, box[i].ra);
		int r = min(box[i].lb, box[i].rb);
		if (l >= r) continue;
		ret += (lld)(r-l>>1)*(arr[i+1].x-arr[i].x>>1);
	}
	return ret;
}

int main()
{
	read(N);
	for (int i=1;i<=N;i++) read(A[i].x, A[i].y);
	lld ans = proc();
	for (int i=1;i<=N;i++) A[i].x++;
	ans += proc();
	write(ans); puts("");
}