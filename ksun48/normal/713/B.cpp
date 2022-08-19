#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a1, b1, a2, b2;
vector<int> d;
void solve(){
	int e = b2;
	int s = b1-1;
	while(s+1 < e){
		int m = (s+e)/2;
		int a;
		if(a1 > a2 || b1 > m){
			a = 0;
		} else {
			cout << "? " << a1 << " " << b1 << " " << a2 << " " << m << endl;
			fflush(stdout);
			cin >> a;
		}
		if(a){
			e = m;
		} else {
			s = m;
		}
	}
	b2 = e;

	e = a2;
	s = a1-1;
	while(s+1 < e){
		int m = (s+e)/2;
		int a;
		if(a1 > m || b1 > b2){
			a = 0;
		} else {
			cout << "? " << a1 << " " << b1 << " " << m << " " << b2 << endl;
			fflush(stdout);
			cin >> a;
		}
		if(a){
			e = m;
		} else {
			s = m;
		}
	}
	a2 = e;

	s = a1;
	e = a2+1;
	while(s+1 < e){
		int m = (s+e)/2;
		int a;
		if(m > a2 || b1 > b2){
			a = 0;
		} else {
			cout << "? " << m << " " << b1 << " " << a2 << " " << b2 << endl;
			fflush(stdout);
			cin >> a;
		}
		if(a){
			s = m;
		} else {
			e = m;
		}
	}
	a1 = s;

	s = b1;
	e = b2+1;
	while(s+1 < e){
		int m = (s+e)/2;
		int a;
		if(a1 > a2 || m > b2){
			a = 0;
		} else {
			cout << "? " << a1 << " " << m << " " << a2 << " " << b2 << endl;
			fflush(stdout);
			cin >> a;
		}
		if(a){
			s = m;
		} else {
			e = m;
		}
	}
	b1 = s;
	d.push_back(a1);
	d.push_back(b1);
	d.push_back(a2);
	d.push_back(b2);
}
int main(){
	int n;
	cin >> n;
	a1 = b1 = 1;
	a2 = b2 = n;
	solve();
	a1 = b1 = 1;
	a2 = n;
	b2 = d[1]-1;
	if(b1 <= b2 && a1 <= a2){
		cout << "? " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
		fflush(stdout);
		int a;
		cin >> a;
		if(a){
			solve();
			cout << "!";
			for(int i = 0; i < 8; i++){
				cout << " " << d[i];
			}
			cout << endl;
			fflush(stdout);
			return 0;
		}
	}

	a1 = b1 = 1;
	b2 = n;
	a2 = d[0]-1;
	if(b1 <= b2 && a1 <= a2){
		cout << "? " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
		fflush(stdout);
		int a;
		cin >> a;
		if(a){
			solve();
			cout << "!";
			for(int i = 0; i < 8; i++){
				cout << " " << d[i];
			}
			cout << endl;
			fflush(stdout);
			return 0;
		}
	}

	a1 = 1;
	b1 = d[3]+1;
	a2 = b2 = n;
	if(b1 <= b2 && a1 <= a2){
		cout << "? " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
		fflush(stdout);
		int a;
		cin >> a;
		if(a){
			solve();
			cout << "!";
			for(int i = 0; i < 8; i++){
				cout << " " << d[i];
			}
			cout << endl;
			fflush(stdout);
			return 0;
		}
	}

	b1 = 1;
	a1 = d[2]+1;
	a2 = b2 = n;
	if(b1 <= b2 && a1 <= a2){
		cout << "? " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
		fflush(stdout);
		int a;
		cin >> a;
		if(a){
			solve();
			cout << "!";
			for(int i = 0; i < 8; i++){
				cout << " " << d[i];
			}
			cout << endl;
			fflush(stdout);
			return 0;
		}
	}

}