/************************************
	Name:  
	E-mail: 1839714778@qq.com 
************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h> 
#include <string>
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
using namespace std;
vector <string> vec;
int n,s;
string ans;

void dfs()
{
	if(s>=vec.size())
	{
		cout<<"Error occurred"<<endl;
		exit(0);
	}
	if(vec[s]=="int")
	{
		s++;
		ans+="int";
		return;
	}
	ans+="pair<";
	s++;
	dfs();
	ans+=',';
	dfs();
	ans+='>';
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin>>n;
	string c;
	while(cin>>c)
	{
		vec.push_back(c);
	}
	dfs();
	if(s!=vec.size())
	{
		cout<<"Error occurred"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}