#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair 
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
bool use[105];
string c[105];

string change(string a,string b)
{
	string ans;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==b[i]) ans+=a[i];else ans+='?';
	} 
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k,t;
	cin>>n>>k;
	rep(n)
	{
		cin>>c[i];
	}
	int len=-1;
	string ans;
	rep(k)
	{
		cin>>t;
		t--;
		use[t]=true;
		if(len==-1)
		{
			len=c[t].size();
			ans=c[t];
		}
		else
		{
			if(c[t].size()!=len)
			{
				cout<<"No\n";
				return 0;
			}
		}
		ans=change(ans,c[t]);
	}
	rep(n)
	{
		if(use[i]) continue;
		if(c[i].size()!=ans.size()) continue;
		for(int j=0;j<ans.size();j++)
		{
			if(ans[j]!='?' && ans[j]!=c[i][j])
			{
				goto next;
			}
		}
		cout<<"No\n";
		return 0;
		next:;
	}
	cout<<"Yes\n";
	cout<<ans<<endl;
	return 0;
}