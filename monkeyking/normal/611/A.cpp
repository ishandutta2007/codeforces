#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(N) for(int i=0;i<N;i++)
using namespace std;

int main()
{
	int a;
	int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
	cin>>a;
	string c;
	cin>>c;
	cin>>c;
	if(c=="week")
	{
		int k=4;
		int s=0;
		a--;
		for(int m=0;m<12;m++)
		{
			for(int d=1;d<=month[m];d++)
			{
				if((k++)%7==a) s++; 
			}
		}
		cout<<s<<endl;
	}
	else
	{
		int s=0;
		for(int i=0;i<12;i++)
		{
			s+=(month[i]>=a);
		}
		cout<<s<<endl;
	}
	return 0;
}