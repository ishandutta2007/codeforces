#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;
int t[19],jed;
int pref(int poz) {
	int re = 0;
	for(int i = poz; i < 7;i++) if(t[i] == 1) re++;
	return re;
}
long long suf(int k) {
	if(k == 0) return k/jed;
	int re = (k - 1)/jed;
	k = k - re * jed;
	re*=7;
	for(int i = 0; i < 7; i ++) {
		if(t[i] == 1) k --;
		re++;
		if(k == 0) {
			// cout <<"eihou"<< re << endl;
			return re;
		}
	}
}
long long idz(int poz,int k) {
	long long re = 0;
	for(int i = poz; i<7;i++) {
		if(t[i] == 1) k--;
		re++;
		if(k == 0) return re;
	}
	return 1e9;
}
int main() {
	ios_base::sync_with_stdio(0);
	int qwe,k;
	cin>>qwe;
	while(qwe--) {
		cin>>k;
		jed = 0;
		for(int i = 0; i < 7; i ++) {
			cin>>t[i];
			if(t[i] == 1) jed++;
		}
		long long wynik = 1e9;
		for(int i = 0; i < 8; i++) {
			wynik = min(wynik, suf(k - pref(i)) + 7 - i);
			wynik = min(wynik, idz(i,k));
		}
		cout << wynik<<endl;
	}
}