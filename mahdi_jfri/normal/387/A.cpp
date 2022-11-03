#include<iostream>
using namespace std;
int main()
{
	int a1,b1,a2,b2;
	string a,b;
	cin>>a>>b;
	a2=(a[0]-48)*10+a[1]-48;
	b2=(b[0]-48)*10+b[1]-48;
	a1=(a2*60+((a[3]-48)*10+a[4]-48));
	b1=(b2*60+((b[3]-48)*10+b[4]-48));
	if(a1<b1)
	a1+=24*60;
	a1-=b1;
	a2=a1/60;
	a1-=a2*60;
	if(a2==0)
	cout<<"00:";
	else if(a2<10)
	cout<<"0"<<a2<<":";
	else
	cout<<a2<<":";
	if(a1==0)
	cout<<"00";
	else if(a1<10)
	cout<<"0"<<a1;
	else
	cout<<a1;
}