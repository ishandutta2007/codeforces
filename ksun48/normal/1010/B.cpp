#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int m, n;
	cin >> m >> n;
	vector<int> p(n, 0);
	for(int i = 0; i < n; i++){
		cout << 1 << endl;
		fflush(stdout);
		int ans;
		cin >> ans;
		if(ans == 0){
			return 0;
		}
		p[i] = ans;
	}
	int cur = 0;
	int s = 0; // too small
	int e = m + 1; // too big
	while(s + 1 < e){
		int m = (s + e) / 2;
		cout << m << endl;
		fflush(stdout);
		int ans;
		cin >> ans;
		ans *= p[cur];
		if(ans == 0){
			return 0;
		}
		if(ans == -1){
			e = m;
		} else {
			s = m;
		}
		cur = (cur + 1) % n;
	}
}