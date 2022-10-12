/**
 *    author:  Mohamed.Abo_Okail
 *    created: o2/o1/2o2o
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	string s; cin >> s;
	string a1 = "", a2 = "", b1 = "", b2 = "", c1 = "", c2 = "";
	ll ar[6] = {0}, arr[6];
	int f = 1;
	for (int i = 0; i < n; i++) {
		if(f == 1) { a1 += 'B'; f = 2; }
		else if(f == 2) { a1 += 'R'; f = 3; }
		else if(f == 3) { a1 += 'G'; f = 1; }
	} f = 1;
	
	for (int i = 0; i < n; i++) {
		if(f == 1) { a2 += 'B'; f = 2; }
		else if(f == 2) { a2 += 'G'; f = 3; }
		else if(f == 3) { a2 += 'R'; f = 1; }
	} f = 1;
 
	for (int i = 0; i < n; i++) {
		if(f == 1) { b1 += 'R'; f = 2; }
		else if(f == 2) { b1 += 'B'; f = 3; }
		else if(f == 3) { b1 += 'G'; f = 1; }
	} f = 1;
	
	for (int i = 0; i < n; i++) {
		if(f == 1) { b2 += 'R'; f = 2; }
		else if(f == 2) { b2 += 'G'; f = 3; }
		else if(f == 3) { b2 += 'B'; f = 1; }
	} f = 1;
 
	for (int i = 0; i < n; i++) {
		if(f == 1) { c1 += 'G'; f = 2; }
		else if(f == 2) { c1 += 'R'; f = 3; }
		else if(f == 3) { c1 += 'B'; f = 1; }
	} f = 1;
	
	for (int i = 0; i < n; i++) {
		if(f == 1) { c2 += 'G'; f = 2; }
		else if(f == 2) { c2 += 'B'; f = 3; }
		else if(f == 3) { c2 += 'R'; f = 1; }
	}
	
	for (int i = 0; i < n; i++) {
		if(s[i] != a1[i]) { ar[0]++; arr[0] = ar[0]; }
		if(s[i] != a2[i]) { ar[1]++; arr[1] = ar[1]; }
		if(s[i] != b1[i]) { ar[2]++; arr[2] = ar[2]; }
		if(s[i] != b2[i]) { ar[3]++; arr[3] = ar[3]; }
		if(s[i] != c1[i]) { ar[4]++; arr[4] = ar[4]; }
		if(s[i] != c2[i]) { ar[5]++; arr[5] = ar[5]; }
	}
	sort(ar, ar + 6);
	cout << ar[0] << endl;
	if(ar[0] == 0) { cout << s << endl;}
	else if(ar[0] == arr[0]) { cout << a1 << endl; }
	else if(ar[0] == arr[1]) { cout << a2 << endl; }
	else if(ar[0] == arr[2]) { cout << b1 << endl; }
	else if(ar[0] == arr[3]) { cout << b2 << endl; }
	else if(ar[0] == arr[4]) { cout << c1 << endl; }
	else if(ar[0] == arr[5]) { cout << c2 << endl; }
}