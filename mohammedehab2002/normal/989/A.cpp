#include <iostream>
#include <set>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for (int i=1;i<s.size()-1;i++)
	{
		set<char> st;
		for (int x=i-1;x<=i+1;x++)
		{
			if (s[x]!='.')
			st.insert(s[x]);
		}
		if (st.size()==3)
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}