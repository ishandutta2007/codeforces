#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint c[100005], t[100005];
vector<llint> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	if(c[1] != t[1] || c[n] != t[n]){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i = 1; i < n; i++) vec.push_back(c[i+1]-c[i]);
	for(int i = 1; i < n; i++) vec2.push_back(t[i+1]-t[i]);
	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end());
	
	if(vec == vec2) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}