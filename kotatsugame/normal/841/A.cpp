#include<iostream>
using namespace std;
main()
{
	int n,k;string s;cin>>n>>k>>s;
	int cnt[99]={};
	for(int i=0;i<n;i++)
	{
		cnt[s[i]-'a']++;
	}
	int M=0;
	for(int i=0;i<26;i++)M=M<cnt[i]?cnt[i]:M;
	cout<<(M<=k?"YES":"NO")<<endl;
}