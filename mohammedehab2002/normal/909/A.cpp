#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> v;
int main()
{
	string a,b;
	cin >> a >> b;
	string tmp="";
	for (int i=0;i<a.size();i++)
	{
		tmp+=a[i];
		string tmp2="";
		for (int x=0;x<b.size();x++)
		{
			tmp2+=b[x];
			v.push_back(tmp+tmp2);
		}
	}
	sort(v.begin(),v.end());
	cout << v[0];
}