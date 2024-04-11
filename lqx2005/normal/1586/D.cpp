#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef double db; 
const int N = 100 + 10;
int n, a[N];
int nxt[N], pre[N];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cout << "? ";
		for(int j = 1; j <= n; j++) cout << 1 + (i == j) <<" ";
		cout << endl;
		int k;
		cin >> k;
		if(k != i && k) nxt[i] = k, pre[k] = i;
	}
	for(int i = 1; i <= n; i++) {
		cout << "? ";
		for(int j = 1; j <= n; j++) cout << 1 + (i != j) <<" ";
		cout << endl;
		int k;
		cin >> k;
		if(k != i && k) nxt[k] = i, pre[i] = k;
	}
	int s = 0, cnt = 0;
	for(int i = 1; i <= n; i++) if(!pre[i]) s = i;
	for(; s; cnt++, a[s] = cnt, s = nxt[s]);
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << a[i] <<" ";
	cout << endl;
    return 0;
}