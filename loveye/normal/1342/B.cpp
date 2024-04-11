#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
char s[N],t[N];
int n;
int main() {
	ios::sync_with_stdio(0);
	int kase;cin >>kase;
	while(kase--) {
		int ok = 1;
		cin >>t+1;
		n = strlen(t+1);
		for(int i = 2;i <= n;++i)
			if(t[i] != t[i-1]) ok = 0;
		if(ok) cout << t+1 << endl;
		else {
			for(int i = 1;i <= n;++i)
				cout <<"01";
			cout << endl;
		}
	}
	return 0;
}