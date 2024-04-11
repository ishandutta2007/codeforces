#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,a,i,ans=0;
	cin >> n >> k;
	for (i=0;i<n;i++)
	{
		cin >> a;
		ostringstream con;
		con << a;
		string s=con.str();
		if (count(s.begin(),s.end(),'4')+count(s.begin(),s.end(),'7')<=k)
		ans++;
	}
	cout << ans;
}