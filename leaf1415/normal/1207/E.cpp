#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define llint long long
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "?";
	for(int i = 0; i < 100; i++) cout << " " << i;
	cout << endl;
	
	llint ans = 0, res;
	cin >> res;
	ans += (res>>7)<<7;
	
	cout << "?";
	for(int i = 1; i <= 100; i++) cout << " " << (i<<7);
	cout << endl;
	
	cin >> res;
	ans += res & ((1<<7)-1);
	cout << "! " << ans << endl;
	
	return 0;
}