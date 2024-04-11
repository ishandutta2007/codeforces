#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string a="au",b="Blbsr";
	int ans=s.size();
	for (int i=0;i<2;i++)
	ans=min(ans,(int)count(s.begin(),s.end(),a[i])/2);
	for (int i=0;i<5;i++)
	ans=min(ans,(int)count(s.begin(),s.end(),b[i]));
	cout << ans;
}