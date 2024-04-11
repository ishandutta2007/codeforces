#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int bigletter=0,smallletter=0;
	for(int i=0;i<s.size();i++)
		if(s[i]<='Z') bigletter++;
		else          smallletter++;
	if(bigletter>smallletter)
		for(int i=0;i<s.size();i++)
			if(s[i]>='a') cout<<(char)(s[i]-'a'+'A');
			else          cout<<s[i];
	if(bigletter<=smallletter)
		for(int i=0;i<s.size();i++)
			if(s[i]<='Z') cout<<(char)(s[i]-'A'+'a');
			else          cout<<s[i];
	cout<<endl;
	return 0;
}