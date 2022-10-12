/**
 *    author:  Mohamed.Abo_Okail
 *    created: 01/01/2020
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, ans = 0; cin >> n;
	vector <int> a4, a8, a15, a16, a23, a42;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		if(x == 4)  { a4.push_back(i);  }
		if(x == 8)  { a8.push_back(i);  }
		if(x == 15) { a15.push_back(i); }
		if(x == 16) { a16.push_back(i); }
		if(x == 23) { a23.push_back(i); }
		if(x == 42) { a42.push_back(i); }
	}
	int i8 = 0, i15 = 0, i16 = 0, i23 = 0, i42 = 0;
	for (int i = 0; i < a4.size(); i++) {
		if(a8.size() <= i || a15.size() <= i || a16.size() <= i || a23.size() <= i || a42.size() <= i) {
			break;
		}
		while(a8[i8] < a4[i]) {
			i8++;
			if(i8 >= a8.size()) { return cout << n - (ans * 6) << endl, 0; }
		}
		while(a15[i15] < a8[i8]) {
			i15++;
			if(i15 >= a15.size()) { return cout << n - (ans * 6) << endl, 0; }
		}
		while(a16[i16] < a15[i15]) {
			i16++;
			if(i16 >= a16.size()) { return cout << n - (ans * 6) << endl, 0; }
		}
		while(a23[i23] < a16[i16]) {
			i23++;
			if(i23 >= a23.size()) { return cout << n - (ans * 6) << endl, 0; }
		}
		while(a42[i42] < a23[i23]) {
			i42++;
			if(i42 >= a42.size()) { return cout << n - (ans * 6) << endl, 0; }
		}
		i8++; i15++; i16++; i23++; i42++; ans++;
	}
	cout << n - (ans * 6) << endl;
}