#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string ask(int x, int y){
	cout << "? " << x << " " << y << '\n';
	fflush(stdout);
	string ans;
	cin >> ans;
	return ans;
}

void guess(int x){
	cout << "! " << x << '\n';
	fflush(stdout);
}

void solve2(LL b){
	int s = b;
	int e = 2 * b;
	while(s + 1 < e){
		int m = (s + e) / 2;
		if(ask(b, m) == "x"){
			e = m;
		} else {
			s = m;
		}
	}
	guess(e);
}

void solve(){
	if(ask(0, 1) == "x"){
		guess(1);
		return;
	}
	LL b = 1;
	while(1){
		if(ask(b, 2*b) == "x"){
			// in (b, 2*b]
			solve2(b);
			return;
		}
		b *= 2;
	}
}

int main(){
	while(1){
		string what;
		cin >> what;
		if(what == "end") break;
		if(what == "mistake") break;
		assert(what == "start");
		solve();
	}
}