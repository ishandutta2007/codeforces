#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
string s;
int fail[N],ch[N][26];
signed main()
{
	register int i,j;
	cin>>n>>k>>s;s='$'+s;
	fail[0]=-1;
	for(i=1;i<=n;fail[i]=j+1,i++)
		for(j=fail[i-1];j!=-1&&s[j+1]!=s[i];j=fail[j]);
	memset(ch,-1,sizeof(ch));
	for(i=0;i<=n;i++)
	{
		if(i<n)
			ch[i][s[i+1]-'a']=i+1;
		if(~fail[i])
			for(j=0;j<26;j++)
				if(!~ch[i][j])
					ch[i][j]=ch[fail[i]][j];
	}
	int x=0;
	for(i=1;i<=k;i++)
		for(j=0;j<26;j++)
			if(~ch[x][j])
			{
				putchar('a'+j),x=ch[x][j];
				break;
			}
	putchar('\n');
	return 0;
}