#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int val[1000][2][5000];

int main(){
	int n, m;
	cin >> n >> m;
	string a1[n];
	int a[n];
	map<string,int> ff;
	for(int i = 0; i < n; i++){
		cin >> a1[i];
		a[i] = i;
		ff[a1[i]] = i;

		string f1;
		cin >> f1;
		string r5;
		cin >> r5;
		//cout << r << endl;
		if(r5[0] == '0' || r5[0] == '1'){
			for(int j = 0; j < m; j++){
				val[j][0][a[i]] = r5[j]-'0';
				val[j][1][a[i]] = r5[j]-'0';
			}
		} else {
			string s, t5;
			cin >> s >> t5;
			for(int j = 0; j < m; j++){
				int r0, t0, r1, t1;
				r0 = t0 = 0;
				r1 = t1 = 1;
				if(r5[0] != '?'){
					int r = ff[r5];
					r0 = val[j][0][r];
					r1 = val[j][1][r];
				}
				if(t5[0] != '?'){
					int t = ff[t5];
					t0 = val[j][0][t];
					t1 = val[j][1][t];
				}
				if(s[0] == 'A'){
					val[j][0][a[i]] = r0 & t0;
					val[j][1][a[i]] = r1 & t1;					
				} else if(s[0] == 'X'){
					val[j][0][a[i]] = r0 ^ t0;
					val[j][1][a[i]] = r1 ^ t1;
				} else if(s[0] == 'O'){
					val[j][0][a[i]] = r0 | t0;
					val[j][1][a[i]] = r1 | t1;							
				}
			}
		}
	}
	vector<int> f;
	vector<int> g;
	for(int j = 0; j < m; j++){
		int c0 = 0;
		int c1 = 0;
		for(int i = 0; i < n; i++){
			c0 += val[j][0][a[i]];
			c1 += val[j][1][a[i]];
			//cout << val[j][0][a[i]] << val[j][1][a[i]] << endl;
		}
		//cout << c0 << " " << c1 << endl;
		if(c0 > c1){
			f.push_back(1);
			g.push_back(0);
		} else if(c0 == c1){
			f.push_back(0);
			g.push_back(0);
		} else if(c0 < c1){
			f.push_back(0);
			g.push_back(1);
		}
	}
	for(int j = 0; j < m; j++){
		cout << f[j];
	}
	cout << endl;
	for(int j = 0; j < m; j++){
		cout << g[j];
	}
	cout << endl;

}