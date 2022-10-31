/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*1000 + 10;

int sum[maxN], tree[maxN];

int n;

int c(int x){
	int sum = 0;
	for(; x> 0; x -= x & (-x))
		sum += tree[x];
	return sum;
}

void update(int i, int val){
	for(; i<=n; i += i & (-i))
		tree[i] += val;
}

map<int,int> a, b;
int val[maxN];
int num[maxN];
 
int main() { 
	ios::sync_with_stdio(false) ; cin.tie(0);
	cin >> n;

	for(int i = 0 ; i < n ;i++ ) { 
		cin >> num[i];
		a[num[i]]++;
		val[i] = a[num[i]];
	}

	long long ans = 0;
	for(int j = n - 1;  j> 0 ; j-- ) { 
		b[num[j]]++;
		update( b[num[j]] , 1 ) ; 
		ans += c( val[j-1]  - 1 ) ;
	}
	cout << ans << endl;
}