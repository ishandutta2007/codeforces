#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	LL a, b;
	cin >> a >> b;
	LL f = 0;
	while((f+1) * (f+2) / 2 <= a + b){
		f++;
	}
	vector<LL> z1;
	vector<LL> z2;
	for(LL x = f; x >= 1; x--){
		if(a >= x){
			a -= x;
			z1.push_back(x);
		} else {
			b -= x;
			z2.push_back(x);
		}
	}
	assert(a >= 0 && b >= 0);
	cout << z1.size() << '\n';
	for(LL x : z1){
		cout << x << " ";
	}
	cout << '\n';
	cout << z2.size() << '\n';
	for(LL x : z2){
		cout << x << " ";
	}
	cout << '\n';
}