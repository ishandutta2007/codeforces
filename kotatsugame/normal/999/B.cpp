#include<iostream>
#include<algorithm>
using namespace std;
int N;
string s;
main()
{
	cin>>N>>s;
	for(int i=1;i<=N;i++)if(N%i==0)reverse(s.begin(),s.begin()+i);
	cout<<s<<endl;
}