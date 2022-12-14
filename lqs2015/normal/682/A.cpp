#include<iostream>
using namespace std;
long long s,x,y,c;
int main()
{
	cin>>x>>y;
	for (long long i=1;i<=x;i++)
	{
		if(i%5==0) s+=y/5;
		else 
		{
			if (y<5-i%5) continue;
			s+=(y-5+i%5)/5+1;
		}
	}
	cout<<s<<endl;
	return 0;
}