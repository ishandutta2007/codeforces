#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;

int n,m;
int l[MAXN],r[MAXN],q[MAXN];
int f[MAXN][32];

int get (int l, int r, int bit){
	if (l == 0)
		return f[r][bit];
	return f[r][bit] - f[l-1][bit];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<m; i++){
		cin >> l[i] >> r[i] >> q[i];
		l[i]--; r[i]--;
		for (int j=0; j<30; j++){
			if (q[i] & (1<<j)){
				f[l[i]][j]++;
				f[r[i]+1][j]--;
			}
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j<30; j++)
			f[i][j]+= f[i-1][j];
	for (int i=0; i<=n; i++)
		for (int j=0; j<30; j++)
			f[i][j] = min(f[i][j],1);
	for (int i=1; i<=n; i++)
		for (int j=0; j<30; j++)
			f[i][j]+= f[i-1][j];
	for (int i=0; i<m; i++){
		bool flag = false;
		for (int j=0; j<30; j++){
			if (!(q[i] & (1<<j))){
				if (get(l[i],r[i],j) == r[i]-l[i]+1)
					flag = true;
			}
		}
		if (flag){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i=0; i<n; i++){
		int val = 0;
		for (int j=0; j<30; j++)
			if (get(i,i,j) == 1)
				val+= (1<<j);
		cout << val << ' ';
	}
	cout << endl;
	return 0;
}