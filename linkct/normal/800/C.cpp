#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005, SQRT = 500;
typedef long long int LL;

int n, m, id[MAXN], f[SQRT], ans[SQRT], tr[SQRT];
bool rm[MAXN]; vector <int> num[SQRT];

int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
void exgcd(int x, int y, int z, LL &a, LL &b){
	if(!y) a = z / x, b = 0;
	else{
		exgcd(y, x % y, z, b, a);
		b -= (x / y) * a;
	}
}
void traceback(int x, int &v){
	if(!x) return;
	traceback(tr[x], v);
	LL a, b;
	for(int i = 0; i < int(num[x].size()); ++ i){
		exgcd(v, m, num[x][i], a, b);
		printf("%d ", int(((a % m) + m) % m));
		v = num[x][i];
	}
}
int main(){
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &j);
		rm[j] = true;
	}
	for(i = 1; i <= m / i; ++ i)
		if(m % i == 0){
			f[++ f[0]] = i;
			if(i != m / i) f[++ f[0]] = m / i;
		}
	sort(f + 1, f + 1 + f[0]);
	for(i = 1; i <= f[0]; ++ i)
		id[f[i]] = i;
	for(i = 1; i < m; ++ i)
		if(!rm[i]) num[id[gcd(i, m)]].push_back(i);
	for(i = 1; i <= f[0]; ++ i){
		ans[i] += num[i].size();
		for(j = 2; j <= f[0] && LL(f[i]) * f[j] <= m; ++ j){
			if(id[f[i] * f[j]] && ans[id[f[i] * f[j]]] < ans[i])
				ans[id[f[i] * f[j]]] = ans[i], tr[id[f[i] * f[j]]] = i;
		}
	} printf("%d\n", ans[f[0]] + 1 - rm[0]);
	traceback(f[0], i = 1);
	if(rm[0] == 0) printf("0");
	return 0;
}