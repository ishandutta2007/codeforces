#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 1){
			cout << -1 << '\n';
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		if(b[i] == 1){
			cout << -1 << '\n';
			return 0;
		}
	}
	double mass = m;
	for(int i = 0; i < a.size(); i++){
		double q = a[i];
		mass *= q / (q-1);
	}
	for(int i = 0; i < b.size(); i++){
		double q = b[i];
		mass *= q / (q-1);
	}
	double ans = mass - (double)(m);
	printf("%.10lf\n", ans);
}