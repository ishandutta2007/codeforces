#include <iostream>

using namespace std;


int a[10];
int b[10];

bool t1w()
{
	if (a[0]>a[2] && a[0]>a[3] && b[1]>b[2] && b[1]>b[3])
		return true;
	if (a[1]>a[2] && a[1]>a[3] && b[0]>b[2] && b[0]>b[3])
		return true;
	return false;
}

bool t2w(int x,int y)
{
	if (a[2]>a[x] && b[3]>b[y])
		return true;
	if (a[3]>a[x] && b[2]>b[y])
		return true;
	return false;
}



int main()
{
	for (int i=0;i<4;++i)
		cin>>a[i]>>b[i];
	swap(a[2],b[2]);
	swap(a[3],b[3]);
	
	if (t1w())
		cout<<"Team 1";
	else if (t2w(0,1) && t2w(1,0) )
		cout<<"Team 2";
	else
		cout<<"Draw";
	
}