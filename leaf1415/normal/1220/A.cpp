#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int cnt[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
	int ncnt = cnt['n'-'a'], zcnt = cnt['z'-'a'];
	
	for(int i = 0; i < ncnt; i++) cout << 1 << " ";
	for(int i = 0; i < zcnt; i++) cout << 0 << " ";
	cout << endl;
	
	return 0;
}