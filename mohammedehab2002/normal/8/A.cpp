#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	string way,a,b,c,d;
	size_t f1,f2;
	int l1,l2,l3,i,x,p=0,arr[]={0,0},test=0,ans;
	cin >> way >> a >> b;
	f1=way.find(a);
	f2=way.rfind(b);
	if (f1!=string::npos && f2!=string::npos && f2>f1+(a.size()-1))
	arr[0]=1;
	reverse(way.begin(),way.end());
	f1=way.find(a);
	f2=way.rfind(b);
	if (f1!=string::npos && f2!=string::npos && f2>f1+(a.size()-1))
	arr[1]=1;
	if (arr[0]==1 && arr[1]==1)
	cout << "both";
	else if (arr[0]==1 && arr[1]==0)
	cout << "forward";
	else if (arr[0]==0 && arr[1]==1)
	cout << "backward";
	else
	cout << "fantasy";
}