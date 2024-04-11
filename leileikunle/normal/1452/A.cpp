#include <iostream>
#include <cmath>
using namespace std;
int get(int x,int y)
{
	if(abs(x-y)<=1) return x+y;
	else return x+y+abs(x-y)-1;
}
int main()
{
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		int c = get(x,y);
		cout<<c<<endl;
	}
}