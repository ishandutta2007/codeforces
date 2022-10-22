#include<iostream>
using namespace std;
int f[200010][30];string s;
int main()
{
	int n,i,j,ans=0;cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>s;int l=s.length(),t[30]={},r[30]={};
		for (j=0;j<l;j++)
		{
			if (j && s[j-1]==s[j]) t[s[j]-'a']++;else t[s[j]-'a']=1;
			r[s[j]-'a']=max(r[s[j]-'a'],t[s[j]-'a']);
		}
		for (j=0;j<26;j++)
		{
			f[i][j]=r[j];
			int t1=0,t2=l-1;while (s[t1]=='a'+j && t1<l) t1++;
			while (s[t2]=='a'+j && t2>t1) t2--;
			if (t1==l) f[i][j]=max(f[i][j],f[i-1][j]*l+l+f[i-1][j]);
			else if (f[i-1][j]) f[i][j]=max(f[i][j],t1+l-t2);
			if (i==n)ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
}