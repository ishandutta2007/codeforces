#include<bits/stdc++.h>
using namespace std;
char s[111111];
int n,sum1,sum2,cur[111111],res,cnt;
int ans,arr[111111];
set<int> l,r;
set<int>::iterator it;
bool f;
void go()
{
	int pos=0;
	while(1)
	{
		if (!f)
		{
			it=l.lower_bound(pos);
			if (it==l.end()) break;
			if (!r.empty() && !l.empty() && (*r.rbegin())<(*it) && (*l.begin())<(*r.begin())) break;
			pos=cur[++cnt]=(*it);
			l.erase(it);
		}
		else
		{
			it=r.lower_bound(pos);
			if (it==r.end()) break;
			if (!r.empty() && !l.empty() && (*l.rbegin())<(*it) && (*r.begin())<(*l.begin())) break;
			pos=cur[++cnt]=(*it);
			r.erase(it);
		}
		f=!f;
	}
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='L') 
		{
			sum1++;
			l.insert(i+1);
		}
		else
		{
			sum2++;
			r.insert(i+1);
		}
	}
	if (sum1==sum2-1)
	{
		f=1;res=-1;
		while(!l.empty() || !r.empty())
		{
			res++;
			go();	
		}
		ans=res;
		for (int i=1;i<=n;i++) arr[i]=cur[i];
	}
	else if (sum1-1==sum2)
	{
		f=0;res=-1;
		while(!l.empty() || !r.empty())
		{
			res++;
			go();	
		}
		ans=res;
		for (int i=1;i<=n;i++) arr[i]=cur[i];
	}
	else
	{
		f=0;res=-1;
		while(!l.empty() || !r.empty())
		{
			res++;
			go();	
		}
		ans=res;
		for (int i=1;i<=n;i++) arr[i]=cur[i];
		res=-1;f=1;cnt=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='L') 
			{
				l.insert(i+1);
			}
			else
			{
				r.insert(i+1);
			}
		}
		while(!l.empty() || !r.empty())
		{
			res++;
			go();	
		}
		if (res<ans)
		{
			ans=res;
			for (int i=1;i<=n;i++) arr[i]=cur[i];
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",arr[i]);
	printf("\n");
	return 0;
}