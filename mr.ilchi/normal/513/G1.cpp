#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30+5;
const int MAXK = 200+10;

bool mark[MAXN][MAXN][MAXK][2];
int n,k;
int p[MAXN];
double dp[MAXN][MAXN][MAXK][2];

double go (int a, int b, int rem, int cmp){
	double &ret = dp[a][b][rem][cmp];
	if (mark[a][b][rem][cmp])
		return ret;
	mark[a][b][rem][cmp] = true;
	if (rem == 0)
		return ret = cmp + 0.0;
	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++){
			int newa = (a<i ? a : a > j ? a : j+i-a);
			int newb = (b<i ? b : b > j ? b : j+i-b);
			int newcmp = (newa < newb ? cmp : 1-cmp);
			if (newa > newb)
				swap(newa, newb);
			ret+= go(newa,newb,rem-1,newcmp)*2.0/n/(n+1.0);
		}
	return ret;
}

int main(){
	cin >> n >> k;
	for (int i=0; i<n; i++){
		cin >> p[i];
		p[i]--;
	}
	double ans = 0.0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			ans+= go(i,j,k,p[i]>p[j]);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}