#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
llint a[2005];
set<llint> S, T;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = 0;
	for(llint i = 0; i <= n; i++){
		T.clear();
		ans = max(ans, i);
		for(int j = n; j >= i+1; j--){
			if(S.count(a[j]) ||  T.count(a[j])) break;
			ans = max(ans, i+(n-j+1));
			T.insert(a[j]);
		}
		if(S.count(a[i+1])) break;
		S.insert(a[i+1]);
	}
	cout << n - ans << endl;
	
	return 0;
}