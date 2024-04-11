#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

string s, ind, t;
map<string, string> ma;
vector<string> ve;

bool read()
{
	bool chk = false, correct = true;
	while (getline(cin, s))
	{
		if (s == "\\begin{thebibliography}{99}")
			break;
		for (char &c : s)
		{
			if (c == '}')
			{
				chk = false;
				ve.push_back(t);
			}
			if (chk)
				t += c;
			if (c == '{')
			{
				chk = true;
				t = "";
			}
		}
	}
	int pos = 0;
	while (getline(cin, s))
	{
		if (s == "\\end{thebibliography}")
			break;
		t = ""; ind = "";
		int phase = 0;
		for (char &c : s)
		{
			if (phase == 2)
				t += c;
			if (c == '}')
			{
				phase = 2;
				if (ve[pos++] != ind)
					correct = false;
			}
			if (phase == 1)
				ind += c;
			if (c == '{')
				phase = 1;
		}
		ma[ind] = t;
	}
	return correct;
}

void write()
{
	cout << "\\begin{thebibliography}{99}\n";
	for (string &s : ve)
		cout << "\\bibitem{" << s << "}" << ma[s] << '\n';
	cout << "\\end{thebibliography}";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (read())
		cout << "Correct\n";
	else
	{
		cout << "Incorrect\n";
		write();
	}
}