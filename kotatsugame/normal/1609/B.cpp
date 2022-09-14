#include<iostream>
using namespace std;
int N,Q;
string S;
bool f(int id)
{
	for(int d=-2;d<=0;d++)
	{
		if(id+d>=0&&S.substr(id+d,3)=="abc")return true;
	}
	return false;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q>>S;
	int cnt=0;
	for(int i=0;i+3<=N;i++)
	{
		if(S.substr(i,3)=="abc")cnt++;
	}
	for(;Q--;)
	{
		int x;char c;
		cin>>x>>c;
		x--;
		if(f(x))cnt--;
		S[x]=c;
		if(f(x))cnt++;
		cout<<cnt<<"\n";
	}
}