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

struct MAP{
	int n, m;
	MAP(): rotated(0) { memset(buf, 0, sizeof(buf)); pt = buf; }
	char buf[300005], *pt;
	bool rotated;
	char& get(int y, int x){
		return rotated ? buf[x*n+y] : buf[y*m+x];
	}
	void concat(const string &s){
		for (char c: s) *(pt++) = c;
	}
	void rotate(){
		rotated ^= 1; swap(n, m);
	}
} A, B, P, Q;

int solve()
{
	vector <char> ord = {'A', 'C', 'G', 'T'};
	int ret = 2e9;
	do{
		int tot = 0;
		Q.n = A.n; Q.m = A.m; Q.rotated = A.rotated;
		for (int i=0;i<A.n;i++){
			int v1 = 0, v2 = 0;
			for (int j=0;j<A.m;j++){
				if (ord[(j&1)+(i&1)*2] != A.get(i, j)) v1++;
				if (ord[(~j&1)+(i&1)*2] != A.get(i, j)) v2++;
			}
			tot += min(v1, v2);
			for (int j=0;j<A.m;j++){
				if (v1 < v2) Q.get(i, j) = ord[(j&1)+(i&1)*2];
				else Q.get(i, j) = ord[(~j&1)+(i&1)*2];
			}
		}
		if (ret > tot)
			ret = tot, P = Q;
	}while (next_permutation(all(ord)));
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> A.n >> A.m;
	for (int i=0;i<A.n;i++){
		string s; cin >> s;
		A.concat(s);
	}
	int ans = solve(); B = P;
	A.rotate();
	int v = solve();
	if (ans > v)
		ans = v, B = P, B.rotate();
	for (int i=0;i<B.n;i++){
		for (int j=0;j<B.m;j++) putchar(B.get(i, j));
		puts("");
	}
}