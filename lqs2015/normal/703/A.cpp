#include<iostream>
using namespace std;
int n,wm,wc,x,y;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		if (x>y) wm++;
		else if (x<y) wc++;
	}
	if (wm>wc) cout<<"Mishka"<<endl;
	else if (wm<wc) cout<<"Chris"<<endl;
	else cout<<"Friendship is magic!^^"<<endl;
	return 0;
}