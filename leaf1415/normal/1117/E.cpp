#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int p[10005];

int main(void)
{
	cin >> s;
	n = s.size();
	
	string t, res;
	for(int i = 0; i < n; i++) t += " ";
	
	for(int i = 0; i < n; i++) t[i] = i%26 + 'a';
	cout << "? " << t << endl;
	cin >> res;
	for(int i = 0; i < n; i++) p[i] += (res[i]-'a');
	
	for(int i = 0; i < n; i++) t[i] = (i/26)%26 + 'a';
	cout << "? " << t << endl;
	cin >> res;
	for(int i = 0; i < n; i++) p[i] += (res[i]-'a')*26;
	
	for(int i = 0; i < n; i++) t[i] = (i/26/26) + 'a';
	cout << "? " << t << endl;
	cin >> res;
	for(int i = 0; i < n; i++) p[i] += (res[i]-'a')*26*26;
	
	string ans;
	for(int i = 0; i < n; i++) ans += " ";
	for(int i = 0; i < n; i++) ans[p[i]] = s[i];
	cout << "! " << ans << endl;
	
	return 0;
}