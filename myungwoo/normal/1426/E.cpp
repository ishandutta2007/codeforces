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

int N, A, B, C, X, Y, Z;

int get(int a, int b, int c, int x, int y, int z)
{
	return min(a, y) + min(b, z) + min(c, x);
}

void tie_down(int &a, int &b)
{
	int c = min(a, b);
	a -= c; b -= c;
}

int get2(int a, int b, int c, int x, int y, int z)
{
	vector <int> perm;
	for (int i=0;i<9;i++) perm.push_back(i);
	int ret = 2e9;
	do{
		int _a = a, _b = b, _c = c, _x = x, _y = y, _z = z;
		for (int v: perm){
			if (v == 0) tie_down(_a, _x);
			if (v == 1) tie_down(_b, _x);
			if (v == 2) tie_down(_b, _y);
			if (v == 3) tie_down(_c, _y);
			if (v == 4) tie_down(_c, _z);
			if (v == 5) tie_down(_a, _z);
			if (v == 6) tie_down(_a, _x);
			if (v == 7) tie_down(_b, _y);
			if (v == 8) tie_down(_c, _z);
		}
		ret = min(ret, _a+_b+_c);
	}while(next_permutation(all(perm)));
	return ret;
}

int main()
{
	read(N, A, B, C, X, Y, Z);
	int mx = get(A, B, C, X, Y, Z);
	int mn = get2(A, B, C, X, Y, Z);
	write(mn); putchar(' ');
	write(mx); putchar('\n');
}