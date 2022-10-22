#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define LL long long
#define I inline void
int T,a,b,c;
int main() {
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		if(a < b ) swap(a,b);
		if(a > 1ll * b * (c + 1)) cout << "No" << endl;
		else cout << "Yes" << endl;
	} 
	return 0;
}