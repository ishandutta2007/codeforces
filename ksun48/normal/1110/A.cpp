#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int b, k;
	cin >> b >> k;
	b %= 2;
	vector<int> a(k);
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < k; i++){
		if(i == 0 || b == 1){
			ans ^= (a[i] & 1);
		}
	}
	if(ans == 0){
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}
}