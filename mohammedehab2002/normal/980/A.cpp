#include <iostream>
using namespace std;
int cnt[2];
int main()
{
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++)
	cnt[(s[i]=='o')]++;
	if (cnt[1]==0 || cnt[0]%cnt[1]==0)
	printf("YES");
	else
	printf("NO");
}