# include <iostream>
using namespace std;
string s;
int main()
{
	cin>>s;
	int p=s.find('0');
	s.erase(s.begin()+(p==-1?0:p));
	cout<<s<<endl;
	return 0;
}