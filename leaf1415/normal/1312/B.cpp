#include <iostream>
#include <algorithm>
#define llint long long
#define rep(i, s, t) for(llint (i) = (s); (i) <= (t); (i)++)

using namespace std;

llint T;
llint n;
llint a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	rep(t, 1, T){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		sort(a+1, a+n+1);
		reverse(a+1, a+n+1);
		rep(i, 1, n) cout << a[i] << " "; cout << endl;
	}
	flush(cout);
	
	return 0;
}