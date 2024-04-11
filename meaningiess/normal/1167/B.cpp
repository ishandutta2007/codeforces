#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,a[10],b[10]={0,4,8,15,16,23,42},T=720;
int check()
{
	for (i=1;i<=4;i++) if (b[i]*b[i+1]!=a[i]) return 0;return 1;
}
int main()
{
	
	cout<<"? "<<1<<' '<<2<<endl;fflush(stdout);cin>>a[1];fflush(stdout);
	cout<<"? "<<2<<' '<<3<<endl;fflush(stdout);cin>>a[2];fflush(stdout);
	cout<<"? "<<3<<' '<<4<<endl;fflush(stdout);cin>>a[3];fflush(stdout);
	cout<<"? "<<4<<' '<<5<<endl;fflush(stdout);cin>>a[4];fflush(stdout);
	while (T--)
	{
		if (check()) {cout<<"!";for (i=1;i<=6;i++) cout<<' '<<b[i];cout<<endl;break;}
		else next_permutation(b+1,b+7);
	}
	
}
/*
4 8 15 16 42 23 

*/