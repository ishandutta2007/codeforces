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
const int N = 1e3 + 10;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	int color = 0, p = n;
	for(; p > 1; p = (p + k - 1) / k) color++;
	printf("%d\n", color);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int c = 0, a = i, b = j;
			for(; a != b; c++, a /= k, b /= k);
			printf("%d ", c);
		}
	}
	printf("\n");
	return 0;
}