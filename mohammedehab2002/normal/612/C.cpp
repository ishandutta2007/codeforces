#include <iostream>
#include <vector>
using namespace std;
vector<char> v;
int arr[200];
int main()
{
	arr['}']='{';
	arr[')']='(';
	arr[']']='[';
	arr['>']='<';
	string s;
	cin >> s;
	int ans=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='{' || s[i]=='<' || s[i]=='(' || s[i]=='[')
		v.push_back(s[i]);
		else
		{
			if (v.empty())
			{
				cout << "Impossible";
				return 0;
			}
			if (v.back()!=arr[s[i]])
			ans++;
			v.pop_back();
		}
	}
	if (v.empty())
	cout << ans;
	else
	cout << "Impossible";
}