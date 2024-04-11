#include<iostream>
using namespace std;
int N;
string S;
main()
{
	cin>>N>>S;
	int mn=0,now=0;
	for(int i=0;i<N;i++)
	{
		if(S[i]=='+')now++;
		else now--;
		if(mn>now)mn=now;
	}
	cout<<now-mn<<endl;
}