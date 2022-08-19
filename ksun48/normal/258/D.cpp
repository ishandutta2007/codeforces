#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

double prob[1000][1000]; //prob i > j
double temp1[1000][1000];
double temp2[1000][1000];
int c, d;
int f(int a){
	if(a == c) return d;
	if(a == d) return c;
	return a;
}

int main(){
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i] > a[j]){
				prob[i][j] = 1;
			} else {
				prob[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < m; i++){
		cin >> c >> d;
		c--; d--;
		vector<int> r, s;
		for(int j = 0; j < n; j++){
			r.push_back(j); s.push_back(c);
			r.push_back(j); s.push_back(d);
			r.push_back(c); s.push_back(j);
			r.push_back(d); s.push_back(j);
		}
		for(int j = 0; j < r.size(); j++){
			int u = r[j]; int v = s[j];
			temp1[u][v] = prob[u][v];
			temp2[u][v] = prob[f(u)][f(v)];
		}
		for(int j = 0; j < r.size(); j++){
			int u = r[j]; int v = s[j];
			prob[u][v] = (temp1[u][v] + temp2[u][v]) / 2.0;
		}
	}
	double ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i < j){
				ans += prob[i][j];
			}
		}
	}
	printf("%.10lf\n", ans);
}