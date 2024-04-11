#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n-1);
	for(int i = 0; i < n-1; i++){
		a[i] = __builtin_ctz(i + 1);
	}
	vector<int> r(n-1), c(n-1);
	for(int i = 0; i < n-1; i++){
		r[i] = 1 << (2 * a[i]);
		c[i] = 1 << (2 * a[i] + 1);
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			sum += r[j];
			cout << r[j] << ' ';
		}
		cout << '\n';
	}
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n; j++){
			sum += c[i];
			cout << c[i] << ' ';
		}
		cout << '\n';
	}
	cout << flush;
	vector<int> rsum(n, 0), csum(n, 0);
	for(int i = 1; i < n; i++){
		rsum[i] = rsum[i-1] ^ r[i-1];
		csum[i] = csum[i-1] ^ c[i-1];
	}
	int k;
	cin >> k;
	int x = 0;
	int y = 0;
	while(k--){
		int loc;
		cin >> loc;
		int ni = -1, nj = -1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((rsum[j] ^ csum[i] ^ rsum[y] ^ csum[x]) == loc){
					ni = i;
					nj = j;
				}
			}
		}
		cout << (ni + 1) << ' ' << (nj + 1) << '\n';
		cout << flush;
		x = ni;
		y = nj;
	}
}