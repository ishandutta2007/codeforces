#include<iostream>
using namespace std;
int h,s,m,t1,t2;
bool f1,f2;
int main()
{
	cin>>h>>m>>s>>t1>>t2;
	if (t1>t2) swap(t1,t2);
	if (h>=t1 && h<t2) f1=1;
	else f2=1;
	if (m>=t1*5 && m<t2*5) f1=1;
	else f2=1;
	if (s>t1*5 && s<t2*5) f1=1;
	else f2=1;
	if (!f1 || !f2) 
	{
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
	return 0;
}