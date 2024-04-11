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

#define MAXN 300005

int N, K, M;
bool used[MAXN];

int main()
{
	read(N, K);
	int total = 0;
	for (M=1;M<=N;M++){
		for (int i=1;i<M&&i*i<=M;i++) if (M%i == 0){
			total++;
			if (i < M/i && M/i < M) total++;
		}
		if (total >= K) break;
	}
	if (total < K) return puts("No"), 0;
	for (int i=1;i<=M;i++) used[i] = 1;
	while (total > K){ // total-K <= 179
		// this while loop only iterate once (experimentally)
		for (int i=1;i<=M;i++) if (used[i]){
			int cnt = 0;
			for (int j=1;j<i&&j*j<=i;j++) if (i%j == 0){
				if (used[j]) cnt++;
				if (j < i/j && i/j < i && used[i/j]) cnt++;
				if (total-cnt < K) break;
			}
			for (int j=i+i;j<=M&&cnt<=total-K;j+=i) if (used[j]) cnt++;
			if (total-cnt >= K) total -= cnt, used[i] = 0;
		}
	}
	vector <int> arr;
	for (int i=1;i<=M;i++) if (used[i]) arr.pb(i);
	puts("Yes");
	write(sz(arr)); puts("");
	for (int i=0;i<sz(arr);i++) write(arr[i]), putchar(i+1 < sz(arr) ? ' ' : '\n');
}