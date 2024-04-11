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

int T, N, M;
struct COL{
	vector <int> row;
	int mx_v;
} cols[2004];
int D[13][1<<12], E[13][1<<12];

int main()
{
	for (read(T);T--;){
		read(N, M);
		for (int i=1;i<=M;i++) cols[i].row.resize(N);
		for (int i=0;i<N;i++) for (int j=1;j<=M;j++)
			read(cols[j].row[i]);
		for (int i=1;i<=M;i++){
			cols[i].mx_v = 0;
			for (int j=0;j<N;j++) cols[i].mx_v = max(cols[i].mx_v, cols[i].row[j]);
		}
		sort(cols+1, cols+M+1, [](const COL &a, const COL &b){
			return a.mx_v > b.mx_v;
		});
		M = min(M, N);
		for (int i=1;i<=M;i++){
			for (int msk=1;msk<(1<<N);msk++){
				E[i][msk] = 0;
				for (int rotate=0;rotate<N;rotate++){
					int v = 0;
					for (int j=0;j<N;j++) if (msk & 1<<j)
						v += cols[i].row[(j+rotate)%N];
					E[i][msk] = max(E[i][msk], v);
				}
			}
		}
		for (int i=1;i<=M;i++){
			for (int msk=1;msk<(1<<N);msk++){
				D[i][msk] = D[i-1][msk];
				for (int nmsk=msk;nmsk;nmsk=nmsk-1&msk)
					D[i][msk] = max(D[i][msk], D[i-1][msk^nmsk]+E[i][nmsk]);
			}
		}
		write(D[M][(1<<N)-1]); puts("");
	}
}