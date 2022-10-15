#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e6 + 7;
int n, a[N];
int tot, f[N];
ll ans, now, sum;
char s[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	L(i, 1, n) f[i] = n + 1;
	L(i, 1, n) a[i] = s[i] - '0';
	int now = 0;
	R(i, n, 1) { //  
		if(a[i]) now++, sum += f[now] - i;
		else {
			L(j, 1, now) f[j] = i + j;
			now = 0; 
		} 
		ans += sum; 
	}
	printf("%lld\n", ans);
	return 0;
}