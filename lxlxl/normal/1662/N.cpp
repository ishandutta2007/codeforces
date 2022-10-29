#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1505;
ll n;
ll a[maxn+5][maxn+5];
ll cntr[maxn+5],cntc[maxn+5];
ll r[maxn*maxn+5],c[maxn*maxn+5];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin >> a[i][j];
			r[a[i][j]]=i;
			c[a[i][j]]=j;
		}
	}
	ll ans=n*(n-1)/2;
	ans=ans*ans*2;
	ll ans2=0;
	for (int now=1;now<=n*n;now++){
		ans2+=cntr[r[now]]*cntc[c[now]];
		cntr[r[now]]++;
		cntc[c[now]]++;
	}
	ans=ans-ans2;
	cout << ans << "\n";
	return 0;
}