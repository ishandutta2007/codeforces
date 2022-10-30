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

#define MAXN 100005

int N, Q;
int A[MAXN];

struct NODE{
	NODE(): a(1), b(0), sum(0), n(0), left(0), right(0) {}
	double a, b, sum; int n;
	NODE *left, *right;
	void propagate(){
		if (!left) return;
		left->apply(a, b);
		right->apply(a, b);
		a = 1; b = 0;
	}
	void apply(double a, double b){
		this->sum = a*this->sum + b*this->n;
		this->a *= a;
		this->b = this->b*a + b;
	}
} *root;

NODE* make_tree(int s, int e)
{
	NODE *ret = new NODE();
	ret->n = e-s+1;
	if (s == e){
		ret->sum = A[s];
		return ret;
	}
	int m = s+e >> 1;
	ret->left = make_tree(s, m);
	ret->right = make_tree(m+1, e);
	ret->sum = ret->left->sum + ret->right->sum;
	return ret;
}

void apply(NODE *now, int s, int e, int l, int r, double a, double b)
{
	if (e < l || s > r) return;
	if (l <= s && e <= r){
		now->apply(a, b);
		return;
	}
	int m = s+e >> 1;
	now->propagate();
	apply(now->left, s, m, l, r, a, b);
	apply(now->right, m+1, e, l, r, a, b);
	now->sum = now->left->sum+now->right->sum;
}

double get(NODE *now, int s, int e, int l, int r)
{
	if (e < l || s > r) return 0;
	if (l <= s && e <= r) return now->sum;
	int m = s+e >> 1;
	now->propagate();
	return get(now->left, s, m, l, r) + get(now->right, m+1, e, l, r);
}

int main()
{
	read(N, Q);
	for (int i=1;i<=N;i++) read(A[i]);
	root = make_tree(1, N);
	while (Q--){
		int t; read(t);
		if (t == 1){
			int l1, r1, l2, r2; read(l1, r1, l2, r2);
			int nl = r1-l1+1, nr = r2-l2+1;
			double sl = get(root, 1, N, l1, r1);
			double sr = get(root, 1, N, l2, r2);
			apply(root, 1, N, l1, r1, (double)(nl-1)/nl, sr/nr/nl);
			apply(root, 1, N, l2, r2, (double)(nr-1)/nr, sl/nl/nr);
		}else{
			int l, r; read(l, r);
			printf("%.9f\n", get(root, 1, N, l, r));
		}
	}
}