#include <iostream>
using namespace std;
void draw(int lev,int h,int* s)
{
	int i;
	int base=h*2+1;
	if (lev>h)
	{
		if (lev==h+1)
		*s=4;
		else
		*s+=4;
		lev=h-lev+h;
	}
	int nums=lev*2+1;
	*s-=2;
	for (i=0;i<*s;i++)
	cout << ' ';
	for (i=0;i<lev;i++)
	cout << i << " ";
	if (lev==0)
	cout << '0';
	else
	cout << lev << " ";
	for (i=lev-1;i>=0;i--)
	{
		if (i==0)
		cout << '0';
		else
		cout << i << " ";
	}
	cout << endl;
}
int main()
{
	int n,i;
	cin >> n;
	int spaces=n*2+2;
	for (i=0;i<n*2+1;i++)
	draw(i,n,&spaces);
}