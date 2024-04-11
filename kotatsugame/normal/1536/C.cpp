#include<iostream>
#include<map>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		map<pair<int,int>,int>mp;
		int d=0,k=0;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='D')d++;
			else k++;
			int g=gcd(d,k);
			printf("%d%c",++mp[make_pair(d/g,k/g)],i+1==N?10:32);
		}
	}
}