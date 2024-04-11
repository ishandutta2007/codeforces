#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	int n1, m1, k1;
	int n2, m2, k2;
	n1 = a/m/k;
	n2 = b/m/k;
	k1 = a % k;
	k2 = b % k;
	m1 = (a/k)%m;
	m2 = (b/k)%m;
	int ans = 0;
	//cout << n1 << " " << m1 << " " << k1 << endl;
	//cout << n2 << " " << m2 << " " << k2 << endl;
	ans += 15*min(abs(n1-n2),n-abs(n1-n2));
	if(n1 == n2){
		int c = abs(m1-m2);
		if(c <= 2){
			ans += 5*c;
		} else {
			ans += 10+c;
		}
	} else {
		int c = abs(m1);
		if(c <= 2){
			ans += 5*c;
		} else {
			ans += 10+c;
		}
		c = abs(m2);
		if(c <= 2){
			ans += 5*c;
		} else {
			ans += 10+c;
		}
	}
	cout << ans << endl;
}