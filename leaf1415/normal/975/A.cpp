#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int n;
string s[1005];
set<string> S;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	
	for(int i = 0; i < n; i++){
		sort(s[i].begin(), s[i].end());
		s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
	}
	
	for(int i = 0; i < n; i++) S.insert(s[i]);
	cout << S.size() << endl;
	
	return 0;
}