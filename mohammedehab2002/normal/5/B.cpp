#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	string c;
	vector <string> vec;
	vector <string> :: iterator it;
	int i=0,l[1000],num=0,maxi,x,test=2,mod1,mod2,map,j,mod3;
	while (getline(cin,c))
	{
		vec.push_back(c);
		num++;
		l[i]=c.size();
		i++;
	}
	out: maxi=l[0];
	for (x=0;x<num;x++)
	{
		if (l[x]>maxi)
		maxi=l[x];
	}
	for (x=0;x<maxi+2;x++)
	cout << "*";
	cout << "\n";
	map=maxi;
	mod1=map%2;
	x=0;
	for (it=vec.begin();it!=vec.end();it++)
	{
		cout << "*";
		mod2=l[x]%2;
		if (mod2==mod1)
		{
			for (j=0;j<(map-l[x])/2;j++)
			cout << " ";
			cout << *it;
			for (j=0;j<(map-l[x])/2;j++)
			cout << " ";
			cout << "*\n";
		}
		else
		{
			mod3=test%2;
			if (mod3==0)
			{
			for (j=0;j<(map-l[x])/2;j++)
			cout << " ";
			cout << *it;
			for (j=0;j<((map-l[x])/2)+1;j++)
			cout << " ";
			cout << "*\n";
			test++;
			}
			else
			{
				for (j=0;j<((map-l[x])/2)+1;j++)
				cout << " ";
				cout << *it;
				for (j=0;j<(map-l[x])/2;j++)
				cout << " ";
				cout << "*\n";
				test++;
			}
		}
		x++;
	}
	for (x=0;x<maxi+2;x++)
	cout << "*";
}