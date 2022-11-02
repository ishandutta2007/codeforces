#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 200005
#define INF 0x3f3f3f3f
int n;
int c[N];
vector<int> v[N];
int vis[N];
vector<pair<int,int> > ans;
#define pr pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back 
void doit(int x,int y) {
	assert(x != y);
	ans.pb(mp(x,y));
	swap(c[x],c[y]);
	c[x] = -c[x];
	c[y] = -c[y];
}
bool cmp(const vector<int> a, const vector<int> b){
	return a.size() < b.size();
}
int cir = 0;
void print() {
	printf("%d\n", (int)ans.size());
	for (auto x : ans) {
		printf("%d %d\n", x.fi, x.se);
	}
}
void work() {
	int rem = cir;
	
	if(v[cir].size() <= 2) {
		for (int i = 1; i + 1 <= cir; i ++ )
		if(v[i].size() > 2) {
			swap(v[i], v[cir]);
			break ; 
		}
	}
	
	for (int i = 1; i + 1 <= cir; i += 2) {
		rem -= 2;
		auto A = v[i], B = v[i + 1];
		doit(A[0], B[0]);
		
		for (int i = 1; i < (int)A.size(); i += 1) doit(A[i], B[0]); 
		for (int i = 1; i < (int)B.size(); i += 1) doit(B[i], A[0]); 
		
		doit(A[0], B[0]);
	} 
	//cerr << cir << endl;
	if(rem) {
		//cerr << "a";
		auto C = v[cir];
		if(C.size() > 2) {
			for (int i = 0; i < (int)C.size() - 2; i += 1) doit(C.back(), C[i]);
			doit(C[0], C[C.size() - 2]);
			doit(C[C.size() - 2], C.back());
			doit(C[0],C.back()); 
		} else if(C.size() != 1) {
		
			if(C[0] == c[C[0]]) return ;
			
			for (int i = 1; i <= n; i += 1) {
				if(c[i] == i) {
					v[cir + 1].push_back(i);
					auto A = v[cir + 1], B = C;
					doit(A[0], B[0]);
		
						for (int i = 1; i < (int)A.size(); i += 1) doit(A[i], B[0]); 
						for (int i = 1; i < (int)B.size(); i += 1) doit(B[i], A[0]); 
						
						doit(A[0], B[0]);
					return ;
				}
			} 
		//	return ;
		//	cerr << " a " << endl;
		//	for (int j = 1; j <= n; j += 1) cout << c[j] << ' ';
		//	cout << endl;
		//	assert(C.size() != 1);
		//	doit(C[0],C.back()); 
		//	doit(C[0],C[0]); 
		//	doit(C.back(),C.back()); 
		}
	} 
}
int __dbg = 0;
int ok = 1;
int main() {
	if(__dbg) {
		srand(time(0));
		n = 10000;
		for (int i = 1; i <= n; i += 1) c[i] = i;
		for (int i = 1; i <= n; i += 1) swap(c[i], c[rand() % n + 1]);
	} else {
		scanf("%d", &n);
		for (int i = 1; i <= n; i += 1) scanf("%d", &c[i]);
	} 

	for (int i = 1; i <= n; i += 1) {
		if(c[i] != i) ok = 0;
	}
		
	if (n == 0 || ok == 1) {
		cout << "0\n";
		return 0;
	}
	
	
	for (int i = 1; i <= n; i += 1) {
		if(!vis[i]) {
			int cur = i;
			cir ++;
			while(!vis[cur]) {
				v[cir].push_back(cur);
				vis[cur] = 1;
				cur = c[cur];
			}
		}
	}
	work();
//	cerr << "A";
	
	assert((int)ans.size() <= n + 1);
	print();
	for (int i = 1; i <= n; i += 1)  assert(c[i] == i);
}