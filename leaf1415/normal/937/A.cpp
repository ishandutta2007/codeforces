#include <iostream>
#include <set>

using namespace std;

int n;
set<int> s;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		s.insert(a);
	}
	int ans = s.size();
	if(s.count(0)) ans--;
	cout << ans << endl;
	return 0;
}