#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int sum[5]={0,0,0,0,0};
	for(int i=0;i<a.size();i+=2)
	{
		if(a[i]=='1')
		sum[0]++;
		else if(a[i]=='2')
		sum[1]++;
		else
		sum[2]++;
	}
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<sum[i];j++)
		{
			if(j+1==sum[i] && sum[i+1]==0 && sum[i+2]==0)cout << i+1;
			else
			cout << i+1 << "+" ;
		}
	}
}