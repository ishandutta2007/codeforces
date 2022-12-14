#include <cstdio>

int n, seq[150005];

inline void swap(int &a, int &b){int t = a; a = b; b = t;}
bool check(){
	int i;
	for(i = 1; i < n; ++ i)
		if(((i & 1) && (seq[i] >= seq[i + 1])) || (((i & 1) ^ 1) && (seq[i] <= seq[i + 1]))) break;
	return !(i < n);
}
bool check(int x){
	if(x <= 0 || x >= n) return true;
	if(x & 1) return seq[x] < seq[x + 1];
	return seq[x] > seq[x + 1];
}
void solve(int st, int ed){
	int res = 0, i, j, k; bool sgn;
	for(i = st; i <= ed; ++ i)
		for(j = i + 1; j <= ed; ++ j){
			swap(seq[i], seq[j]);
			if(check()) ++ res;
			swap(seq[i], seq[j]);
		}
	for(i = st; i <= ed; ++ i){
		for(j = 1; j <= n; ++ j){
			if(j >= st && j <= ed) continue;
			swap(seq[i], seq[j]);
			for(k = st - 1, sgn = true; k <= ed; ++ k)
				if(!check(k)) sgn = false;
			if((!check(j - 1)) || (!check(j))) sgn = false;
			if(sgn) ++ res;
			swap(seq[i], seq[j]);
		}
	}
	printf("%d\n", res);
}
int main(){
	int i, u, v, j, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &seq[i]);
	for(i = 1; i <= n; ++ i)
		if(((i & 1) && (seq[i] >= seq[i + 1])) || (((i & 1) ^ 1) && (seq[i] <= seq[i + 1]))) break;
	for(j = n; j; -- j)
		if(((j & 1) && (seq[j] >= seq[j - 1])) || (((j & 1) ^ 1) && (seq[j] <= seq[j - 1]))) break;
	if(j - i <= 2){
		solve(i, j);
		return 0;
	}
	for(u = i; u <= i + 1; ++ u)
		for(v = j; v >= j - 1; -- v){
			swap(seq[u], seq[v]);
			if(check()) ++ ans;
			swap(seq[u], seq[v]);
		}
	printf("%d\n", ans);
	return 0;
}