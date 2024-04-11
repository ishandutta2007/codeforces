#include<iostream>
#include<algorithm>
using namespace std;
long long A,B,C;
main()
{
	cin>>A>>B>>C;
	cout<<"First"<<endl;
	long long D=1e10;
	cout<<D<<endl;
	int id;cin>>id;
	long long a,d;
	if(id==1)
	{
		A+=D;
		a=abs(B-C);
		d=A-max(B,C)-a;
	}
	else if(id==2)
	{
		B+=D;
		a=abs(A-C);
		d=B-max(A,C)-a;
	}
	else if(id==3)
	{
		C+=D;
		a=abs(A-B);
		d=C-max(A,B)-a;
	}
	cout<<3*a+2*d<<endl;
	cin>>id;
	if(id==1)
	{
		A+=3*a+2*d;
	}
	else if(id==2)
	{
		B+=3*a+2*d;
	}
	else if(id==3)
	{
		C+=3*a+2*d;
	}
	long long T[3]={A,B,C};
	sort(T,T+3);
	cout<<T[1]-T[0]<<endl;
	cin>>id;
}