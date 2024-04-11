#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<LL> z;
	z.push_back(0);
	for(int i = 0; i < n/2; i++){
		LL a;
		cin >> a;
		LL x = -1;
		LL y = -1;
		for(LL b = 1; b * b < a; b++){
			if(a % b == 0){
				LL d = a/b;
				if((b + d) % 2 == 0){
					LL r = (d - b) / 2;
					LL s = (d + b) / 2;
					if(r * r <= z.back()) continue;
					if(y == -1 || s*s < y){
						x = r * r;
						y = s * s;
					}
				}
			}
		}
		if(y == -1){
			cout << "No" << '\n';
			return 0;
		}
		z.push_back(x);
		z.push_back(y);
	}
	for(int i = 0; i + 1 < z.size(); i++){
		if(z[i] >= z[i+1]){
			cout << "No" << '\n';
			return 0;
		}
	}
	cout << "Yes" << '\n';
	for(int i = 0; i + 1 < z.size(); i++){
		cout << z[i+1] - z[i] << ' ';
	}
	cout << '\n';

}