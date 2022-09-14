#include<iostream>
using namespace std;
int n,m,s;
main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int a,b;cin>>a>>b;
		if(a<=s)s=b<s?s:b;
	}
	cout<<(s<m?"NO":"YES")<<endl;
}