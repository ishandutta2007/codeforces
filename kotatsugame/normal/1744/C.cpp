#include<iostream>
using namespace std;
int N;
char c;
string S;
int ans[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>c>>S;
		int id=0;
		while(S[id]!='g')id++;
		int now=0;
		int ret=0;
		for(int t=0;t<N;t++)
		{
			if(S[id]=='g')now=0;
			ans[id]=now;
			if(S[id]==c)ret=max(ret,now);
			now++;
			id=(id+N-1)%N;
		}
		cout<<ret<<"\n";
	}
}