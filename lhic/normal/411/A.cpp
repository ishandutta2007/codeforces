#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string s;

int main()
{
	cin>>s;
	if (s.size()<5)
	{
		cout<<"Too weak";
		return 0;
	}
	bool hasD=false;
	bool hasS=false;
	bool hasB=false;
	
	for (int i=0;i<s.size();++i)
	{
		if (isdigit(s[i]))
			hasD=true;
		if (islower(s[i]))
			hasS=true;
		if (isupper(s[i]))
			hasB=true;
	}
	if (hasD && hasB && hasS)
		cout<<"Correct";
	else
		cout<<"Too weak";
}