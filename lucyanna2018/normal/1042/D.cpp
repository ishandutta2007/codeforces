#include<bits/stdc++.h>
using namespace std;
#define i64 long long int
#define ran 200020
int n,lb;
i64 a[ran],b[ran],T;

int bit[ran];
int lowbit(int x) { return x & -x; }
void add(int x) {
	while (x <= lb) {
		bit[x] ++;
		x += lowbit(x);
	}
}
int query(int x) {
	int r = 0;
	while (x) {
		r += bit[x];
		x -= lowbit(x);
	}
	return r;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> T;
	b[lb++] = 0;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
		b[lb++] = a[i];
	}
	sort(b,b+lb);
	lb=unique(b,b+lb)-b;
	i64 res = 0;
	for(int i=1; i<=n; i++){
		add(lower_bound(b,b+lb,a[i-1])-b+1);
		res += i-query(lower_bound(b,b+lb,a[i] - T + 1)-b);
	}
	cout << res << endl;
	return 0;
}