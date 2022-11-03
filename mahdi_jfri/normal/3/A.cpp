#include <iostream>
using namespace std;
int ghadr(int a)
{
	if(a<0)
	a*=-1;
	return a;
}
int main()
{
	string a,b;
	cin>>a>>b;
	int x=a[0]-b[0];
	int y=a[1]-b[1];
	int z=max(ghadr(x),ghadr(y));
	cout<<z<<endl;
	while(x!=0 && y!=0)
	{
		if(x>0)
		{cout<<"L"; x--;}
		else
		{cout<<"R"; x++;}
		if(y>0)
		{cout<<"D\n"; y--;}
		else
		{cout<<"U\n"; y++;}
	}
	while(x!=0)
	{
		if(x>0)
		{cout<<"L\n"; x--;}
		else
		{cout<<"R\n"; x++;}
	}
	while(y!=0)
	{
		if(y>0)
		{cout<<"D\n"; y--;}
		else
		{cout<<"U\n"; y++;}
	}
}