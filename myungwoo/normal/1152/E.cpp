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

#define MAXN 100005

int N;
int A[MAXN], B[MAXN];
unordered_map <int, unordered_multiset<int>> con;

/*
 *   ,    ,      
 * ,     path  
 *  0    
 */

vector <int> path;
void dfs(int n)
{
	while (sz(con[n])){
		int t = *con[n].begin();
		con[n].erase(con[n].begin());
		con[t].erase(con[t].find(n));
		dfs(t);
	}
	path.pb(n);
}

int main()
{
	read(N);
	for (int i=1;i<N;i++) read(A[i]);
	for (int i=1;i<N;i++) read(B[i]);
	for (int i=1;i<N;i++){
		//    
		if (A[i] > B[i]) return puts("-1"), 0;
		con[A[i]].insert(B[i]);
		con[B[i]].insert(A[i]);
	}
	int odd = 0, st = con.begin()->first;
	for (auto it: con){
		if (sz(it.second)&1) odd++, st = it.first;
	}

	//    2  
	if (odd > 2) return puts("-1"), 0;
	dfs(st);

	//    0  ,  0       
	//   
	if (sz(path) != N) return puts("-1"), 0;
	for (int t: path) write(t), putchar(' '); puts("");
}