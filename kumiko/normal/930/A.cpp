#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

const int N = 100100;
int n;
int p[N], c[N], cnt[N];

int main(){
	scanf("%d", &n);

	cnt[0] = 1;
	for(int i = 2; i <= n; ++i){
		scanf("%d", p + i);
		c[i] = c[p[i]] + 1;
		cnt[c[i]] ^= 1;
	}

	int sum = 0;
	for(int i = 0; i < n; ++i) sum += cnt[i];
	printf("%d\n", sum);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}