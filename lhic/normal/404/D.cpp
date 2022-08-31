#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s;

const int M=1000000007;

const int MAX_N=1100000;

int arr[MAX_N][3];


int main()
{
	cin>>s;
	
	arr[0][0]=1;
	arr[0][2]=1;
	for (int i=1;i<(int)s.size()+1;++i)
	{
		if (s[i-1]=='*')
		{
			arr[i][0]=0;
			arr[i][1]=arr[i-1][2];
			arr[i][2]=arr[i-1][2];
		}
		if (s[i-1]=='0')
		{
			arr[i][0]=arr[i-1][0];
			arr[i][1]=0;
			arr[i][2]=0;
		}
		if (s[i-1]=='1')
		{
			arr[i][0]=arr[i-1][1];
			arr[i][1]=0;
			arr[i][2]=arr[i-1][0];
		}
		if (s[i-1]=='2')
		{
			arr[i][0]=0;
			arr[i][1]=0;
			arr[i][2]=arr[i-1][1];
		}
		if (s[i-1]=='?')
		{
			arr[i][0]=(arr[i-1][0]+arr[i-1][1])%M;
			arr[i][1]=arr[i-1][2];
			arr[i][2]=((arr[i-1][0]+arr[i-1][1])%M+arr[i-1][2])%M;
		}
		
	}
	
	cout<<(arr[s.size()][0]+arr[s.size()][1])%M;
	
}