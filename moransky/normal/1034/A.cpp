#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int N = 300005, S = 15000001;
int n, a[N], primes[S], tot = 0, cnt[S]; 
bool st[S];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main(){
	int res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		res = gcd(res, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		a[i] /= res;
		cnt[a[i]]++;
	}

	res = 1e9;
	for (int i = 2; i < S; i++) {
		if(!st[i]) primes[++tot] = i;
		for (int j = 1; i * primes[j] < S; j++) {
			st[i * primes[j]] = true;
			if(i % primes[j] == 0) break;
		}
	}
	for (int i = 1; i <= tot; i++) {
		
		int num = 0, v = primes[i];
		for (int j = v; j < S; j += v)
			 num += cnt[j]; 
		res = min(res, n - num);
	}
	if(res >= n) res = -1;
	printf("%d\n", res);
	return 0;
}