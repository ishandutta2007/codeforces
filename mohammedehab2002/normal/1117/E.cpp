#include <iostream>
using namespace std;
string t;
int pos[26][26][26];
string send(int l)
{
	string tmp="? ";
	for (int i=0;i<t.size();i++)
	tmp+=(i%l)+'a';
	cout << tmp << endl;
	string ret;
	cin >> ret;
	return ret;
}
int main()
{
	cin >> t;
	for (int i=0;i<t.size();i++)
	pos[i%26][i%25][i%23]=i;
	cout.flush();
	string a=send(26),b=send(25),c=send(23),s=t;
	for (int i=0;i<t.size();i++)
	s[pos[a[i]-'a'][b[i]-'a'][c[i]-'a']]=t[i];
	cout << "! "+s;
}