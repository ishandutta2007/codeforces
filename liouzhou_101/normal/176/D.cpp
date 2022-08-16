#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxLen=1000010;
const int MaxN=2010;

int n,len;
char s[MaxLen];
int L[MaxN],R[MaxN];
int next[MaxLen][26];
int w[MaxN];

int m;
int a[MaxN];
int pnext[MaxN][26];

int tlen;
char t[MaxN];

pair<int,int> F[MaxN][MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		L[i]=len+1;
		scanf("%s",s+len+1);
		R[i]=(len+=strlen(s+len+1));
	}
	for (int i=0;i<26;++i)
		next[len+1][i]=len+1;
	for (int i=len;i>=1;--i)
		for (int j=0;j<26;++j)
			next[i][j]=(s[i]==j+'a')?i:next[i+1][j];
	for (int i=1;i<=n;++i)
		for (int j=L[i];j<=R[i];++j)
			w[i]|=1<<(s[j]-'a');
	cin>>m;
	for (int i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for (int i=0;i<26;++i)
		pnext[m+1][i]=m+1;
	for (int i=m;i>=0;--i)
		for (int j=0;j<26;++j)
			pnext[i][j]=(w[a[i]]&(1<<j))?i:pnext[i+1][j];
	scanf("%s",t+1);
	tlen=strlen(t+1);
}

void work()
{
	for (int i=1;i<=tlen;++i)
		F[i][0]=make_pair(m+1,len+1);
	int ans=0;
	for (int i=1;i<=tlen;++i)
	{
		for (int j=1;j<=tlen;++j)
		{
			F[i][j]=F[i][j-1];
			int x=F[i-1][j-1].first,y=F[i-1][j-1].second;
			if (x>m) continue;
			if (next[y+1][t[j]-'a']<=R[a[x]])
				F[i][j]=min(F[i][j],make_pair(x,next[y+1][t[j]-'a']));
			else
			{
				x=pnext[x+1][t[j]-'a'];
				if (x>m) continue;
				F[i][j]=min(F[i][j],make_pair(x,next[L[a[x]]][t[j]-'a']));
			}
			if (F[i][j].second<=len) ans=max(ans,i);
		}
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}