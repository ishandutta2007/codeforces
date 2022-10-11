#include <iostream>
using namespace std;
int cnt[26];
int main()
{
	int n,k;
	string s;
	cin >> n >> k >> s;
	for (int i=0;i<s.size();i++)
	cnt[s[i]-'a']++;
	for (int i=0;i<26;i++)
	{
		if (cnt[i]>k)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}