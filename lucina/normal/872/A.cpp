#include <stdio.h>
#include <bits/stdc++.h>
#define st first
#define nd second
#define PQ priority_queue
#define MP make_pair

using ll = long long ;
using namespace std;
using pii = pair<int,int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
const int N = 0;
const int MOD = 0;
bool occ[2][10];
int main(){
	int n, m, x;
	scanf("%d %d", &n, &m);
	int mi_1 = 10, mi_2 = 10;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		mi_1 = min(mi_1, x);
		occ[0][x] = true;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &x);
		mi_2 = min(mi_2, x);
		occ[1][x] = true;	
	}
	for (int i = 1; i < 10; i ++) if(occ[0][i] && occ[1][i]) return !printf("%d", i);
	printf("%d%d", min(mi_1, mi_2), max(mi_1, mi_2));
}