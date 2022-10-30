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

int N;

void construct(int n, string &p, string &u, char c)
{
	if (n <= 4){
		p = string(1, c);
		u = string(n-1, c);
		return;
	}
	string p2, u2;
	if (n&1){
		construct(n-1>>1, p2, u2, c+1);
		p = p2+string(1, c);
		u = u2+string(2, c);
	}else{
		construct(n-2>>1, p2, u2, c+1);
		p = p2+string(1, c);
		u = string(1, c)+u2+string(2, c);
	}
}

int main()
{
	read(N);
	string p, u;
	construct(N, p, u, 'a');
	printf("%s %s\n", (p+u).c_str(), p.c_str());
}