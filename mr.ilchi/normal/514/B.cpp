#include <bits/stdc++.h>
using namespace std;

bool mark[2000];
int x[2000],y[2000];

int main(){
	int n,x0,y0;
	cin >> n >> x0 >> y0;
	int ans = 0;
	for (int i=0; i<n; i++) cin >> x[i] >> y[i];
	for (int i=0; i<n; i++) if (!mark[i]){
		mark[i] = true;
		for (int j=i+1; j<n; j++) if (!mark[j]){
			int dx = x[i]-x0, dy = y[i]-y0;
			int dxx= x[j]-x0, dyy= y[j]-y0;
			if (dx*dyy == dxx*dy)
				mark[j] = true;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}