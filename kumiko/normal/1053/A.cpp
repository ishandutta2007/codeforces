#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	if(2LL * n * m % k != 0){
		puts("NO");
		return 0;
	}
	if(k & 1){
		int g1 = __gcd(n, k);
		if(g1 > 1){
			puts("YES");
			int g2 = k / g1;
			puts("0 0");
			printf("%d 0\n", 2 * n / g1);
			printf("0 %d\n", m / g2);
		}else{
			puts("YES");
			int g2 = __gcd(m, k);
			g1 = k / g2;
			puts("0 0");
			printf("%d 0\n", n / g1);
			printf("0 %d\n", 2 * m / g2);
		}
	}else{
		puts("YES");
		k /= 2;
		int g1 = __gcd(n, k);
		int g2 = k / g1;
		puts("0 0");
		printf("%d 0\n", n / g1);
		printf("0 %d\n", m / g2);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}