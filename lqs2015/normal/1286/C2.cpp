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
}arr[111],cur,all[111];
int n,len,l;
char s[111],aa[5],bb[5],ans[111];
multiset<str> a[111];
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
	if (n==2)
	{
		printf("? 1 1\n");
		fflush(stdout);
		scanf("%s",aa);
		printf("? 2 2\n");
		fflush(stdout);
		scanf("%s",bb);
		s[0]=aa[0];s[1]=bb[0];
		s[2]='\0';
		printf("! %s\n",s);
		return 0;
	}
	len=(n+1)/2;
	printf("? %d %d\n",1,len);
	fflush(stdout);
	for (int i=1;i<=len*(len+1)/2;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		cur=str();
		for (int j=0;j<l;j++) cur.arr[s[j]-'a']++;
		a[l].insert(cur);
	}
	printf("? %d %d\n",1,len-1);
	fflush(stdout);
	for (int i=1;i<=len*(len-1)/2;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		cur=str();
		for (int j=0;j<l;j++) cur.arr[s[j]-'a']++;
		a[l].erase(a[l].find(cur));
	}
	ans[len-1]=fuck(*a[1].begin());
	for (int i=2;i<=len;i++)
	{
		ans[len-i]=fuck((*a[i].begin())-(*a[i-1].begin()));
	}
	printf("? %d %d\n",1,n);
	fflush(stdout);
	for (int i=1;i<=n*(n+1)/2;i++)
	{
		scanf("%s",s);
		l=strlen(s);
		for (int j=0;j<l;j++) all[l].arr[s[j]-'a']++;
	}
	ans[n]='\0';int cr=n;
	for (int i=2;i<=n-len+1;i++)
	{
		for (int j=0;j<len;j++)
		{
			for (int k=j;k<len && k<=j+i-1;k++)
			{
				all[i].arr[ans[k]-'a']--;
			}
		}
		for (int j=n-1;j>=cr;j--)
		{
			all[i].arr[ans[j]-'a']-=(n-j);
		}
		for (int j=0;j<26;j++) all[i].arr[j]%=i;
		ans[n-i+1]=fuck(all[i]);
		cr--;
	}
	printf("! %s\n",ans);
	return 0;
}