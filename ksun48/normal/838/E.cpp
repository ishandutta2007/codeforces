#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<double> x, y;
int n;
double dist(int i, int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double dpl[3000][3000];
double dpr[3000][3000];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		x.push_back(a); y.push_back(b);
		dpl[i][i] = 0;
		dpr[i][i] = 0;
	}
	double ans = 0;
	for(int diff = 1; diff <= n-1; diff++){
		for(int i = 0; i < n; i++){
			int j = (i + diff) % n;
			dpl[i][j] = max(dpl[(i+1)%n][j] + dist(i,(i+1)%n), dpr[(i+1)%n][j] + dist(i,j));
			dpr[i][j] = max(dpr[i][(j+n-1)%n] + dist((j+n-1)%n,j), dpl[i][(j+n-1)%n] + dist(i,j));
			ans = max(ans, dpl[i][j]);
			ans = max(ans, dpr[i][j]);
		}
	}
	printf("%.10lf\n", ans);
}