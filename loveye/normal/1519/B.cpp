#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define LL long long
#define I inline void
int n,m,k,t;
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		if(k == n*m-1) cout <<"Yes" <<endl;
		else cout <<"No" <<endl; 
	}
	return 0;
}