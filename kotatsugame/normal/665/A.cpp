#include<iostream>
using namespace std;
int a,ta,b,tb;
int h,w;
main()
{
	cin>>a>>ta>>b>>tb;
	char c;
	cin>>h>>c>>w;
	int L=h*60+w,R=L+ta;
	int cnt=0;
	for(int T=5*60;T<24*60;T+=b)
	{
		int l=T,r=T+tb;
		if(!(r<=L||R<=l))cnt++;
	}
	cout<<cnt<<endl;
}