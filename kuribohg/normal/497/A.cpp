#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=2010;
int n,m,ans;
string a[MAXN];
bool t[MAXN],ok;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int p=0;p<m;p++)
	{
		ok=true;
		for(int i=1;i<n;i++)
			if(!t[i]&&a[i][p]>a[i+1][p]) ok=false;
		if(!ok) {ans++;continue;}
		for(int i=1;i<n;i++)
			if(a[i][p]!=a[i+1][p]) t[i]=true;
	}
	cout<<ans<<endl;
	return 0;
}