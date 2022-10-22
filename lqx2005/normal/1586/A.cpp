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
const int N = 200 + 10;
int a[N];
int isprime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; ) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if(!isprime(sum)) {
			printf("%d\n", n);
			for(int i = 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
		} else {
			printf("%d\n", n - 1);
			int f = 1;
			for(int i = 1; i <= n; i++) {
				if((a[i] & 1) && f) {
					f = 0;
					continue;
				} else {
					printf("%d ", i);
				}
			}
			printf("\n");
		}
	}
    return 0;
}