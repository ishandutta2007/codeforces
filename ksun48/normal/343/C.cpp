#include <iostream>
using namespace std;
typedef long long LL;
int main() {
	int n, m;
	cin >> n >> m;
	LL h[n];
	LL p[m];
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < m; i++){
		cin >> p[i];
	}
	LL s = -1; //cannot read
	LL e = 22000000000; // can read
	while(s + 1 < e){
		LL d = (s+e)/2;
		//cout << d << endl;
		int k = 0;
		for(int i = 0; i < n; i++){
			if(k == m) break;
			if(h[i] <= p[k]){
				while(p[k] <= h[i]+d){
					k++;
					if(k == m) break;
				}
			} else if(h[i]-p[k] <= d){
				LL m1 = h[i] - p[k];
				LL b;
				if(d >= 3*m1){
					b = d-2*m1;
				} else {
					b = (d-m1)/2;
				}
				while(p[k] <= h[i]+b){
					k++;
					if(k == m) break;
				}
			}
		}
		if(k == m){
			e=d;
		} else {
			s=d;
		}
	}
	cout << e << endl;
	return 0;
}