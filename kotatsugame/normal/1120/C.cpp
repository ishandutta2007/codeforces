#line 1 "a.cpp"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#line 1 "/home/kotatsugame/library/string/Zalgo.cpp"
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#line 3 "/home/kotatsugame/library/string/Zalgo.cpp"
#include<string>
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
#line 6 "a.cpp"
int N,A,B;
string S;
vector<int>T[5050];
int dp[5050];
main()
{
	cin>>N>>A>>B>>S;
	for(int i=0;i<N;i++)T[i]=Zalgo(S.substr(i));
	for(int i=1;i<=N;i++)dp[i]=1e9;
	for(int i=0;i<N;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+A);
		int mx=0;
		for(int j=0;j<i;j++)
		{
			mx=max(mx,min(T[j][i-j],i-j));
		}
		for(int j=1;j<=mx;j++)
		{
			dp[i+j]=min(dp[i+j],dp[i]+B);
		}
	}
	printf("%d\n",dp[N]);
}