#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MAXF 4096
int BIT2[MAXF][MAXF];
void upd2(int x, int y, int v){
	int c = x+1;
	while(c < MAXF){
		int d = y+1;
		while(d	< MAXF){
			BIT2[c][d] += v;
			d += d & -d;
		}
		c += c & -c;
	}	
}

int q2(int x, int y){
	int c = x+1;
	int a = 0;
	while(c > 0){
		int d = y+1;
		while(d	> 0){
			a += BIT2[c][d];
			d -= d & -d;
		}
		c -= c & -c;
	}
	return a;
}

int main(){
	for(int i = 0; i < MAXF; i++) for(int j = 0; j < MAXF; j++) BIT2[i][j] = 0;
	int n, m;
	cin >> n >> m;
	string a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			upd2(i,j,a[i][j]-'0');
		}
	}
	int ans = n*m;
	for(int p = 2; p < 2700; p++){
		int ok = 0;
		for(int i = 0; i < n; i += p){
			for(int j = 0; j < m; j += p){
				int i2 = min(i + p, n)-1;
				int j2 = min(j + p, m)-1;
				int t = q2(i2,j2) - q2(i2,j-1) - q2(i-1,j2) + q2(i-1,j-1);
				ok += min(t, p*p-t);
			}
		}
		ans = min(ans, ok);
		//if(p <= 7) cout << ok << endl;
	}
	cout << ans << endl;
}