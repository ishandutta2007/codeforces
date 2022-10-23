#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string S;
		cin>>N>>S;
		vector<char>A;
		for(char c:S)
		{
			if(A.empty()||A.back()!=c)A.push_back(c);
		}
		if(A.size()==1)cout<<"0\n";
		else if(A[0]=='0')cout<<A.size()-2<<"\n";
		else cout<<A.size()-1<<"\n";
	}
}