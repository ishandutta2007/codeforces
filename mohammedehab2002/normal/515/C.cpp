#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	string s,ans="",facts[]={"","","2","3","322","5","53","7","7222","7332"};
	cin >> n >> s;
	for (i=0;i<n;i++)
	ans+=facts[s[i]-'0'];
	sort (ans.begin(),ans.end());
	reverse (ans.begin(),ans.end());
	cout << ans;
}