# include <iostream>
# include <cstdio>
# include <set>
using namespace std;

long long f[52];

int a[52];

void pre() {
	f[0] = 1;
	for(int i = 1; i <= 50; ++i) {
		if(i > 0) f[i] += f[i-1];
		if(i > 1) f[i] += f[i-2];
		//for(int j = 0; j < i; ++j) f[i] += f[j];
	}
}

void calc(int n,long long k) {
	int j;
	for(int i = 1; i <= n; i = j + 1) {
		j = i;
		while(k > f[n - j]) {
			k -= f[n - j];
			++j;
		}
		for(int k = i; k <= j; ++k)
			a[k] = (i + j - k);
	}
	for(int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	pre();
	int n; cin >> n;
	long long k; cin >> k;
	calc(n, k);
}