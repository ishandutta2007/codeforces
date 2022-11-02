/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() { 
	int n;
	cin >> n;
	if (n == 1)
	{
		string t;
		cin.ignore();
		getline(cin, t);
		if (t == "int")
			cout << t << endl;
		else
			cout << "Error occurred" << endl;
		return 0;
	}
	string ans = "";
	string s;
	int cnt=0;
	while (cin >> s)
	{
		if (cnt != 0 && st.empty())
		{
			cout << "Error occurred" << endl;
			return 0;
		}
		cnt++;
		if (s == "int")
			if (st.empty())
			{
				cout << "Error occurred" << endl;
				return 0;
			}
			else
				if (st.top() == 1)
				{
					ans += ",int";
					while (!st.empty() && st.top() == 1)
					{
						st.pop();
						ans += '>';
					}
					if (!st.empty())
					{
						st.pop();
						st.push(1);
					}

				}
				else
				{
					st.pop();
					ans += "int";
					st.push(1);
				}
		else
		{
			if (st.empty() || st.top() == 0)
				ans += "pair<";
			else
				ans += ",pair<";
			st.push(0);
		}
	}
	if (!st.empty())
		cout << "Error occurred" << endl;
	else
		cout << ans << endl;

}