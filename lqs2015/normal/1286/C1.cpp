#include<bits/stdc++.h>
using namespace std;
struct str
{
	int arr[26];
	str()
	{
		memset(arr,0,sizeof(arr));
	}
	bool operator < (const str &u) const
	{
		for (int i=0;i<26;i++)
		{
			if (arr[i]!=u.arr[i]) return arr[i]<u.arr[i];
		}
		return 0;
	}
	bool operator == (const str &u) const
	{
		for (int i=0;i<26;i++)
		{
			if (arr[i]!=u.arr[i]) return 0;
		}
		return 1;
	}
	str operator + (const str &u) const
	{
		str res;
		for (int i=0;i<26;i++)
		{
			res.arr[i]=arr[i]+u.arr[i];
		}
		return res;
	}
	str operator - (const str &u) const
	{
		str res;
		for (int i=0;i<26;i++)
		{
			res.arr[i]=arr[i]-u.arr[i];
		}
		return res;
	}
}arr[111],cur;
char s[111],ans[111];
multiset<str> a[111];
int n,cnt[111];
char fuck(str s)
{
	for (int i=0;i<26;i++)
	{
		if (s.arr[i]) return 'a'+i;
	}
}
int main()
{
	scanf("%d",&n);
	if (n==1)
	{
		printf("? 1 1\n");
		fflush(stdout);
		scanf("%s",s);
		printf("! %s\n",s);
		fflush(stdout);
		return 0;
	}
	printf("? %d %d\n",1,n);
	fflush(stdout);
	for (int i=1;i<=n*(n+1)/2;i++)
	{
		scanf("%s",s);
		cur=str();int ln=strlen(s);
		for (int j=0;j<ln;j++) cur.arr[s[j]-'a']++;
		a[ln].insert(cur);
	}
	printf("? %d %d\n",1,n-1);
	fflush(stdout);
	for (int i=1;i<=(n-1)*n/2;i++)
	{
		scanf("%s",s);
		cur=str();int ln=strlen(s);
		for (int j=0;j<ln;j++) cur.arr[s[j]-'a']++;
		a[ln].erase(a[ln].find(cur));
	}
	ans[n]='\0';ans[n-1]=fuck(*a[1].begin());
	for (int i=2;i<=n;i++)
	{
		ans[n-i]=fuck((*a[i].begin())-(*a[i-1].begin()));
	}
	printf("! %s\n",ans);
	fflush(stdout);
	return 0;
}