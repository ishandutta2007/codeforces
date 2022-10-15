/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)

#define N 1000005


char s[2313];
int readop() {
	scanf("%s", s);
	return s[0];
}

struct Node {
	int v[2];
	int &operator [] (int x) {return v[x];}
	Node () {v[0] = v[1] = 0;}
	Node (int a, int b) {v[0] = a, v[1] = b;}
};

int n;
int a[N][2], o[N], v[N];

int ans[N];

void dfs(int x) {
	if (o[x] == 'I') {v[x] = a[x][0]; return;}
	if (o[x] == 'N') dfs(a[x][0]);
	else dfs(a[x][0]), dfs(a[x][1]);
	switch (o[x]) {
		case 'N' : v[x] = !v[a[x][0]]; break;
		case 'A' : v[x] = v[a[x][0]] & v[a[x][1]]; break;
		case 'X' : v[x] = v[a[x][0]] ^ v[a[x][1]]; break;
		case 'O' : v[x] = v[a[x][0]] | v[a[x][1]]; break;
	}
}

void getans(int x, Node y) {
//	cerr << x << endl;
//	cerr << x << " " << y[0] << " " << y[1] << endl;
	switch (o[x]) {
		case 'I' : ans[x] = y[a[x][0] ^ 1]; break; 
		case 'N' : getans(a[x][0], Node(y[1], y[0])); break;
		case 'A' : getans(a[x][0], Node(y[0], v[a[x][1]] ? y[1] : y[0]));
				   getans(a[x][1], Node(y[0], v[a[x][0]] ? y[1] : y[0]));
				   break;
		case 'X' : getans(a[x][0], Node(v[a[x][1]] ? y[1] : y[0], v[a[x][1]] ? y[0] : y[1]));
				   getans(a[x][1], Node(v[a[x][0]] ? y[1] : y[0], v[a[x][0]] ? y[0] : y[1]));
				   break;
		case 'O' : getans(a[x][0], Node(v[a[x][1]] ? y[1] : y[0], v[a[x][1]] ? y[1] : y[1]));
				   getans(a[x][1], Node(v[a[x][0]] ? y[1] : y[0], v[a[x][0]] ? y[1] : y[1]));
				   
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		o[i] = readop();
		if (o[i] == 'N' || o[i] == 'I') read(a[i][0]);
		else read(a[i][0]), read(a[i][1]);
	}
	dfs(1);
	getans(1, Node(0, 1));
	for (int i = 1; i <= n; i++) if (o[i] == 'I') printf("%d", ans[i]); 
	return 0;
}