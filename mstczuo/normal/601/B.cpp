# include <bits/stdc++.h>
using namespace std;

int a[100010], n, q;
int c[100010][18];

void pre() {
    for(int i = 1; i <= n; ++i) c[i][0] = i;
    for(int j = 1; j < 18; ++j) {
	for(int i = 1; i + (1<<j) - 1 <= n; ++i) {
	    int il = c[i][j - 1], ir = c[i + (1<<(j-1))][j - 1];
	    c[i][j] = a[il] > a[ir] ? il : ir;
	}
    }
}

int getMaxId(int l,int r) {
    int len = r - l + 1;
    int k = int(log(len) / log(2) + 1e-8);
    int il = c[l][k], ir = c[r - (1<<k) + 1][k];
    return a[il] > a[ir] ? il : ir;
}

long long calc(int l,int r) {
    int id = getMaxId(l, r);
    long long ret = 1ll * (id - l + 1) * (r - id + 1) * a[id];
    if(l < id) ret += calc(l, id - 1);
    if(id < r) ret += calc(id + 1, r);
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) 
	scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i) 
	a[i] = abs(a[i + 1] - a[i]);
    pre();
    while(q--) {
	int l, r; 
	scanf("%d%d", &l, &r);
	r -= 1;
	printf("%I64d\n", calc(l, r));
    }
}