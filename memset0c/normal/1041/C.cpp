// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 200010;

int n, m, d, t, sum;
int a[maxn], ans[maxn];

struct node {
    int id, v;
    bool operator < (const node &p) const{
		return v < p.v;
	}
} u;
set < node > S;
set < node > ::iterator it;

int main() {
//	freopen("C.in", "r", stdin);
//	freopen("C.out", "w", stdout);
	
    n = read(), m = read(), d = read() + 1;
    for (int i = 1; i <= n; i++)
		a[i] = read();
    for (int i = 1; i <= n; i++)
		S.insert((node){i, a[i]});
    while (S.size()){
        t++;
    	it = S.lower_bound((node){0, 1});
    	sum = it->v;
        while (true) {
            if (it == S.end())
				break;
            ans[it->id] = t;
			sum += d;
			S.erase(it);
			it = S.lower_bound((node){0, sum});
            if (it != S.end())
				sum = it->v;
        }
    }
    printf("%d\n", t);
    for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	puts("");
    
	return 0;
}