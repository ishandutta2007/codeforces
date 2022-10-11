#include <iostream>
#include <set>
using namespace std;
set<char> st;
int main()
{
	int n,ans=0;
	string s;
	cin >> n >> s;
	s+="A";
	for (int i=0;i<s.size();i++)
	{
		if (s[i]<='Z')
		ans=max(ans,(int)st.size()),st.clear();
		else
		st.insert(s[i]);
	}
	cout << ans;
}