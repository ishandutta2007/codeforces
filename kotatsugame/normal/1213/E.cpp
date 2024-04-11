#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
int N;
string s,t;
void test(string S)
{
	for(int i=0;i+1<N*3;i++)
	{
		if(S[i]==s[0]&&S[i+1]==s[1])return;
		if(S[i]==t[0]&&S[i+1]==t[1])return;
	}
	cout<<"YES"<<endl;
	cout<<S<<endl;
	exit(0);
}
main()
{
	cin>>N>>s>>t;
	vector<char>A={'a','b','c'};
	do{
		{
			string t="";
			for(char c:A)t+=c;
			string s="";
			for(int i=0;i<N;i++)s+=t;
			test(s);
		}
		{
			string s="";
			for(char c:A)s+=string(N,c);
			test(s);
		}
		{
			string t="";
			t+=A[0];t+=A[1];
			string s="";
			for(int i=0;i<N;i++)s+=t;
			s+=string(N,A[2]);
			test(s);
		}
		{
			string s="";
			s+=string(N,A[0]);
			string t="";
			t+=A[1];t+=A[2];
			for(int i=0;i<N;i++)s+=t;
			test(s);
		}
	}while(next_permutation(A.begin(),A.end()));
	cout<<"NO"<<endl;
}