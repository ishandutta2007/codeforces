#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint l, r;

bool check(llint x)
{
	set<int> S;
	for(;x;x/=10){
		if(S.count(x%10)) return false;
		else S.insert(x%10);
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l >> r;
	for(int i = l; i <= r; i++){
		if(check(i)){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}