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

#define MAXN 300005

int N;
int X[MAXN], Y[MAXN];

void flip_x(){ for (int i=1;i<=N;i++) X[i] = -X[i]; }
void flip_y(){ for (int i=1;i<=N;i++) Y[i] = -Y[i]; }

int solve()
{
	int max_x = X[1], max_y = Y[1];
	for (int i=1;i<=N;i++){
		max_x = max(max_x, X[i]);
		max_y = max(max_y, Y[i]);
	}
	int ret = 0;
	for (int i=1;i<=N;i++)
		ret = max(ret, (max_x-X[i])+(max_y-Y[i])<<1);
	return ret;
}

template <class RandomAccessIterator>
RandomAccessIterator _max(RandomAccessIterator s, RandomAccessIterator e)
{
	auto ret = s;
	for (auto it=s;it!=e;it++) if (*ret < *it) ret = it;
	return ret;
}

template <class RandomAccessIterator>
RandomAccessIterator _min(RandomAccessIterator s, RandomAccessIterator e)
{
	auto ret = s;
	for (auto it=s;it!=e;it++) if (*ret > *it) ret = it;
	return ret;
}

int main()
{
	read(N);
	for (int i=1;i<=N;i++) read(X[i], Y[i]);
	int f4 = *_max(X+1, X+N+1)-*_min(X+1, X+N+1)+*_max(Y+1, Y+N+1)-*_min(Y+1, Y+N+1)<<1;
	int f3 = solve();
	flip_x(); f3 = max(f3, solve());
	flip_y(); f3 = max(f3, solve());
	flip_x(); f3 = max(f3, solve());
	for (int i=3;i<=N;i++) write(i < 4 ? f3 : f4), putchar(i < N ? ' ' : '\n');
}