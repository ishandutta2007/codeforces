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

#define MAXN 104

int N, R;
int D[60001];
struct Z{
	int a, b;
} A[MAXN];

int main()
{
	read(N, R);
	for (int i=1;i<=N;i++) read(A[i].a, A[i].b);
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.a < b.a;
	});
	int base = 0;
	for (int i=1;i<=N;i++) if (A[i].b >= 0 && A[i].a <= R) R += A[i].b, base++;
	vector <Z> arr;
	for (int i=1;i<=N;i++) if (A[i].b < 0) arr.pb(A[i]);
	sort(all(arr), [](const Z &a, const Z &b){
		return a.a+a.b > b.a+b.b;
	});
	for (Z &z: arr){
		for (int i=z.a;i<=R;i++) if (i+z.b >= 0) D[i+z.b] = max(D[i+z.b], D[i]+1);
	}
	int ans = 0;
	for (int i=0;i<=R;i++) ans = max(ans, D[i]);
	write(ans+base); puts("");
}