#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int G[200][2];
int mex(vector<int>A)
{
	bool ex[100]={};
	for(int a:A)ex[a]=true;
	int i=0;
	while(ex[i])i++;
	return i;
}
int gru(int n,int b)
{
	if(n>=200)n=(n-100)%17+100;
	return G[n][b];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n=1;n<200;n++)
	{
		{//even
			vector<int>to;
			for(int l=0;l<n;l++)to.push_back(G[l][0]^G[n-l-1][0]);
			for(int l=0;l<n-1;l++)to.push_back(G[l][1]^G[n-l-2][1]);
			G[n][0]=mex(to);
		}
		{//odd
			vector<int>to;
			for(int l=0;l<n;l++)to.push_back(G[l][0]^G[n-l-1][1]);
			G[n][1]=mex(to);
		}
	}
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string S;
		cin>>N>>S;
		int rcbc=0;
		for(char c:S)
		{
			if(c=='R')rcbc++;
			else rcbc--;
		}
		if(rcbc<0)
		{
			cout<<"Bob\n";
			continue;
		}
		if(rcbc>=1)
		{
			cout<<"Alice\n";
			continue;
		}
		int X=0;
		for(int i=0;i<N;)
		{
			int j=i+1;
			while(j<N&&S[j-1]!=S[j])j++;
			int len=j-i;
			if(len%2==0)
			{
				X^=gru(len/2,0);
			}
			else
			{
				X^=gru(len/2,1);
			}
			i=j;
		}
		cout<<(X?"Alice\n":"Bob\n");
	}
}