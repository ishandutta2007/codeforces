#include <iostream>
using namespace std;
int main()
{
	int n,pos=0,b=1;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		string s;
		int a;
		cin >> a >> s;
		if (pos==0 && s!="South")
		b=0;
		if (pos==20000 && s!="North")
		b=0;
		if (s=="North")
		pos-=a;
		if (s=="South")
		pos+=a;
		if (pos>20000 || pos<0)
		b=0;
	}
	if (pos!=0)
	b=0;
	if (b)
	cout << "YES" << endl;
	else
	cout << "NO" << endl;
}