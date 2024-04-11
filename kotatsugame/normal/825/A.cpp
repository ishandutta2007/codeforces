#include<iostream>
using namespace std;
int N;
string S;
main()
{
	cin>>N>>S;
	S+='0';
	int ret=0;
	for(int i=0;i<S.size();)
	{
		int j=i;
		while(j<S.size()&&S[j]=='1')j++;
		ret=ret*10+j-i;
		i=j+1;
	}
	cout<<ret<<endl;
}