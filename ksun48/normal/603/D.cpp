#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
	if(a < 0) return gcd(-a,b);
	if(b < 0) return -gcd(a,-b);
	if(b == 0) return a;
	return gcd(b,a%b);
}
int main(){
	LL n;
	cin >> n;
	LL a[n], b[n], c[n];
	for(LL i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
		//cout << b[i]*c[i] << " " << a[i]*c[i] << " " << a[i]*a[i]+b[i]*b[i] << endl;
		int g1 = gcd(b[i]*c[i],a[i]*a[i]+b[i]*b[i]);
		int g2 = gcd(a[i]*c[i],a[i]*a[i]+b[i]*b[i]);
		//cout << b[i]*c[i]/g1 << " " << (a[i]*a[i]+b[i]*b[i])/g1 << " " << (a[i]*c[i])/g2 << " " << (a[i]*a[i]+b[i]*b[i])/g2 << endl;
	}
	LL ans = 0;
	for(LL i = 0; i < n; i++){
		multiset<pair<LL,LL> > slopes;
		LL num = n-1;
		for(LL j = 0; j < n; j++){
			if(j == i) continue;
			LL x = b[i]*c[i]*(a[j]*a[j]+b[j]*b[j])-b[j]*c[j]*(a[i]*a[i]+b[i]*b[i]);
			LL y = a[i]*c[i]*(a[j]*a[j]+b[j]*b[j])-a[j]*c[j]*(a[i]*a[i]+b[i]*b[i]);
			if(x == 0 && y == 0){
				num--;
				ans += num;
			} else {
				LL g = gcd(x,y);
				x /= g;
				y /= g;
				if(y == 0 && x < 0) x = -x;
				ans += slopes.count(make_pair(x,y));
				slopes.insert(make_pair(x,y));
			}
		}
	}
	cout << ans/3 << endl;
}