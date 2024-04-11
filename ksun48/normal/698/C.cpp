#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
double nck[100][100];
vector<int> c;
int bsum[1<<20];
int main(){
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < 30; j++){
			if(j == 0 || j == i){
				nck[i][j] = 1.0;
			} else if(j > i){
				nck[i][j] = 0.0;
			} else {
				nck[i][j] = nck[i-1][j-1] + nck[i-1][j];
			}
		}
	}
	int n, k;
	cin >> n >> k;
	double p[n];
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < (1<<20); i++){
		int a = i;
		bsum[i] = 0;
		while(a > 0){
			bsum[i] += a % 2;
			a /= 2;
		}
	}
	for(int i = 0; i < n; i++){
		if(p[i] == 0){
			cout << "0.000 ";
			continue;
		}
		double ans = 0;
		for(int s = 0; s < (1<<n); s++){
			if(bsum[s] > (k-1)) continue;
			if((s >> i) % 2) continue;
			double pw = 0;
			for(int j = 0; j < n; j++){
				if((s >> j ) % 2) pw += p[j];
			}
			int a = n-1;
			int b = k-1;
			double c = 1.0/(1.0-pw);
			double r = 0;
			int l = bsum[s];
			for(int j = l; j <= b; j++){
				if((j-l) % 2 == 0){
					r += nck[a-l][j-l];
				} else {
					r -= nck[a-l][j-l];
				}
			}
			ans += c*r*p[i];
		}
		printf("%.10lf ", ans);
	}
	cout << endl;
}