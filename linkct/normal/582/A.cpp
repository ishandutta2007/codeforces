#include <cstdio>
#include <map>
using namespace std;

map <int, int> cnt;
map <int, int> :: iterator it;
int n, A[505];

int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
int main(){
	int i, j, t;
	scanf("%d", &n);
	for(i = 1; i <= n * n; ++ i){
		scanf("%d", &t);
		++ cnt[t];
	}
	for(i = 1; i <= n; ++ i){
		it = cnt.end(); -- it;
		printf("%d ", A[i] = it -> first);
		if((-- it -> second) == 0) cnt.erase(it);
		for(j = 1; j < i; ++ j)
			if((cnt[gcd(A[i], A[j])] -= 2) == 0) cnt.erase(gcd(A[i], A[j]));
	}
	return 0;
}