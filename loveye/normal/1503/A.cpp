#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,a[N],b[N],sa[N],sb[N];
string s;
int main() {
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		cin >>s;
		int cnta = 0,cntb = 0,ok = 1;
		for(int i = 0;i < n;++i)
			if(s[i] == '1') a[i] = b[i] = 1,++cnta,++cntb;
			else {
				if(cnta > cntb) ++cntb,--cnta,b[i] = 1,a[i] = 0;
				else ++cnta,--cntb,b[i] = 0,a[i] = 1;
				if(cnta < 0 || cntb < 0) {ok = 0;break;}
			}
		sa[0] = a[0];
		for(int i = 1;i < n;++i) sa[i] = sa[i-1] + a[i];
		sb[0] = b[0];
		for(int i = 1;i < n;++i) sb[i] = sb[i-1] + b[i];
		/*
		for(int i = 0;i < n;++i) cout << (a[i] ? '(' : ')');
		cout << endl;
		for(int i = 0;i < n;++i) cout << (b[i] ? '(' : ')');
		cout << endl;
		cout << "YES" <<endl;
		*/
		for(int i = n-1;i >= 0;--i) {
			if(cnta == 0 && cntb == 0) break;
			if(s[i] == '1') {
				if(cnta >= 2 && cntb >= 2 && sa[i] >= 2 && sb[i] >= 2) cnta -= 2,cntb -= 2,a[i] = b[i] = 0;
			} else if(cnta != cntb) {
				if(cnta > cntb) cnta -= 2,cntb += 2,a[i] = 0,b[i] = 1;
				else cntb -= 2,cnta += 2,a[i] = 1,b[i] = 0;
			}
		}
		if(ok == 0 || cnta || cntb || s[n-1] == '0') {
			cout <<"NO" << endl;
			continue;
		}
		cout << "YES" <<endl;
		for(int i = 0;i < n;++i) cout << (a[i] ? '(' : ')');
		cout << endl;
		for(int i = 0;i < n;++i) cout << (b[i] ? '(' : ')');
		cout << endl;
	}
	return 0;
}