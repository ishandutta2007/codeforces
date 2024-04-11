#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	multiset<int> a;
	for(int i = 0; i < 2*n; i++){
		int b;
		cin >> b;
		a.insert(b);
	}
	for(int i = 0; i < n; i++){
		int c = *a.begin();
		multiset<int>::iterator q= a.end();
		q--;
		int d = *q;
		cout << c << " " << d << endl;
		a.erase(a.find(c));
		a.erase(a.find(d));
	}
}