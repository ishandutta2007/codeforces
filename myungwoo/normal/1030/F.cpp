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

const int MOD = 1e9+7;
int N, Q;
int X[MAXN], W[MAXN];

struct VALUE{
	// sw = sum of w_i
	// swi = sum of w_i*i
	// swx = sum of w_i*x_i
	lld sw;
	int swi, swx;
	VALUE operator + (const VALUE &ot)const{
		VALUE ret;
		ret.sw = sw+ot.sw;
		ret.swi = (swi+ot.swi)%MOD;
		ret.swx = (swx+ot.swx)%MOD;
		return ret;
	}
} zero = {0, 0, 0};

struct NODE{
	NODE(): left(0), right(0) {}
	VALUE v;
	void renew(){
		v = left->v+right->v;
	}
	NODE *left, *right;
} *root;

NODE *make_tree(int s, int e)
{
	NODE *ret = new NODE();
	if (s == e){
		ret->v = {
			W[s],
			(int)((lld)W[s]*s%MOD),
			(int)((lld)W[s]*X[s]%MOD),
		};
	}else{
		int m = s+e >> 1;
		ret->left = make_tree(s, m); ret->right = make_tree(m+1, e);
		ret->renew();
	}
	return ret;
}

VALUE get(NODE *now, int s, int e, int l, int r)
{
	if (e < l || s > r) return zero;
	if (l <= s && e <= r)
		return now->v;
	int m = s+e >> 1;
	return get(now->left, s, m, l, r)+get(now->right, m+1, e, l, r);
}

void write(NODE *now, int s, int e, int n, int v)
{
	if (e < n || s > n) return;
	if (s == e){
		now->v = {
			v,
			(int)((lld)v*s%MOD),
			(int)((lld)v*X[s]%MOD),
		};
		return;
	}
	int m = s+e >> 1;
	write(now->left, s, m, n, v);
	write(now->right, m+1, e, n, v);
	now->renew();
}

int get_mid(NODE *now, int s, int e, int l, int r, lld &sw)
{
	if (e < l || s > r || l > r) return 0;
	if (l <= s && e <= r && sw > now->v.sw){
		sw -= now->v.sw;
		return 0;
	}
	if (s == e) return s;
	int m = s+e>>1;
	if (int tmp = get_mid(now->left, s, m, l, r, sw)) return tmp;
	return get_mid(now->right, m+1, e, l, r, sw);
}

int main()
{
	read(N, Q);
	for (int i=1;i<=N;i++) read(X[i]);
	for (int i=1;i<=N;i++) read(W[i]);
	root = make_tree(1, N);
	while (Q--){
		int l, r; read(l, r);
		if (l < 0){
			write(root, 1, N, -l, r);
		}else{
			VALUE all = get(root, 1, N, l, r);
			lld bound = all.sw+1 >> 1;
			int mid = get_mid(root, 1, N, l, r, bound);
			VALUE vl = get(root, 1, N, l, mid-1);
			VALUE vr = get(root, 1, N, mid+1, r);
			int ans = ((
				+ (vl.sw%MOD*X[mid]%MOD-vl.swx+MOD)%MOD
				+ (vr.swx-vr.sw%MOD*X[mid]%MOD+MOD)%MOD
				- (vl.sw*mid-vl.swi)%MOD
				- (vr.swi-vr.sw*mid)%MOD
			)%MOD+MOD)%MOD;
			write(ans); puts("");
		}
	}
}