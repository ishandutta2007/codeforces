#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[5];
int us11[30][30],us12[30][30],us2[30][30][30];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,flg=0;cin>>n;
		memset(us11,0,sizeof(us11));
		memset(us12,0,sizeof(us12));
		memset(us2,0,sizeof(us2));
		for (i=1;i<=n;i++)
		{
			cin>>a;
			int tp=strlen(a);
			if (tp==1) flg=1;
			else if (tp==2 && a[0]==a[1]) flg=1;
			else if (tp==2)
			{
				if (us11[a[1]-'a'][a[0]-'a'] || us12[a[1]-'a'][a[0]-'a']) flg=1;
				us11[a[0]-'a'][a[1]-'a']=1;
			}
			else if (a[0]==a[2]) flg=1;
			else
			{
				if (us11[a[2]-'a'][a[1]-'a']) flg=1;
				if (us2[a[2]-'a'][a[1]-'a'][a[0]-'a']) flg=1;
				us12[a[0]-'a'][a[1]-'a']=us2[a[0]-'a'][a[1]-'a'][a[2]-'a']=1;
			}
			a[0]=a[1]=a[2]=0;
		}
		if (flg) puts("YES");else puts("NO");
	}
}