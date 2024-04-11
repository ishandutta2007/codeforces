#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<utility>
#include<iomanip>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

int main()
{
	string s,t;
	cin>>s>>t;
	int c=0;
	char check[26];
	for(int i=0;i<26;i++)check[i]='*';
	int sl=s.length();
	for(int i=0;i<sl;i++)
	{
		if(check[s[i]-'a']=='*')
		{
			check[s[i]-'a']=t[i];
			check[t[i]-'a']=s[i];
			if(c>=0&&s[i]!=t[i])c++;
		}
		else if(check[s[i]-'a']!=t[i])
		{
			c=-1;
		}
	}
	if(c>=0)for(int i=0;i<sl;i++)
	{
		if(check[t[i]-'a']!=s[i])
		{
			c=-1;
			break;
		}
	}
	if(c<0)cout<<c<<endl;
	else
	{
		cout<<c<<endl;
		int m[26][26]={};
		memset(m,0,sizeof(m));
		for(int i=0;i<26;i++)
		{
			if(check[i]!='*'&&check[i]!='a'+i)m[check[i]-'a'][i]=1;
		}
		for(int i=0;i<26;i++)
		{
			for(int j=i+1;j<26;j++)
			{
				if(m[i][j]>0)cout<<char('a'+i)<<" "<<char('a'+j)<<endl;
			}
		}
	}
	return 0;
}