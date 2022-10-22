#include <iostream>
#include <map>
#include <utility>
#include <stdlib.h>

using namespace std;
typedef pair<int, int> P;

int n;
int a[200005], b[200005];
map<P, int> mp;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			if(b[i] == 0) ans++;
			continue;
		}
		int sgn = a[i]/abs(a[i]) * b[i]/abs(b[i]);
		int d = gcd(a[i], b[i]);
		mp[make_pair(a[i]/d, b[i]/d)]++;
	}
	
	int mx = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		mx = max(mx, it->second);
	}
	cout << ans + mx << endl;
	
	return 0;
}