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

#define MAXN 200005

const int MOD = 1e9 + 7;
int N, D[MAXN], P[MAXN], E[MAXN], Q[MAXN];
char A[MAXN];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> A+1;
	D[0] = 1;
	for (int i=1;i<=N;i++){
		if (A[i] == 'b' || A[i] == 'c') D[i] = D[i-1], P[i] = P[i-1];
		else if (A[i] == 'a') D[i] = D[i-1], P[i] = (P[i-1]+D[i-1]) % MOD;
		else D[i] = D[i-1]*3LL%MOD, P[i] = (P[i-1]*3LL+D[i-1]) % MOD;
	}
	E[N+1] = 1;
	for (int i=N;i;i--){
		if (A[i] == 'a' || A[i] == 'b') E[i] = E[i+1], Q[i] = Q[i+1];
		else if (A[i] == 'c') E[i] = E[i+1], Q[i] = (Q[i+1]+E[i+1]) % MOD;
		else E[i] = E[i+1]*3LL%MOD, Q[i] = (Q[i+1]*3LL+E[i+1]) % MOD;
	}
	int ans = 0;
	for (int i=1;i<=N;i++) if (A[i] == 'b' || A[i] == '?'){
		// debug("%d: %d\n", i, (lld)P[i-1]*Q[i+1]%MOD);
		ans = (ans + (lld)P[i-1]*Q[i+1]%MOD) % MOD;
	}
	write(ans); putchar('\n');
}