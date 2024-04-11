#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int t,n,ok;
char s[N],a[N],b[N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> s+1;
		ok = 0;
		for(int i = 1;i <= n;++i) {
			if(!ok) {
				if(s[i] == '2') a[i] = '1',b[i] = '1';
				if(s[i] == '0') a[i] = '0',b[i] = '0';
				if(s[i] == '1') ok = 1,a[i] = '1',b[i] = '0';
			}
			else {
				a[i] = '0';b[i] = s[i];
			}
		}
		cout << a+1 << endl << b+1 << endl;
		memset(a,0,sizeof(char)*(n+4));
		memset(b,0,sizeof(char)*(n+4));
	}
	return 0;
}