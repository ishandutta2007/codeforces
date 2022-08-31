#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=1<<17;

int n;
char s[MaxN];
vector<int> v,w;
int way[MaxN];

void init()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;++i)
	{
		if (s[i]=='(')
			v.push_back(i);
		else if (s[i]==')')
		{
			if (v.empty()) continue;
			way[*v.rbegin()]=i;
			v.pop_back();
		}
		else if (s[i]=='[')
			w.push_back(i);
		else if (s[i]==']')
		{
			if (w.empty()) continue;
			way[*w.rbegin()]=i;
			w.pop_back();
		}
	}
}

int check(int L,int R)
{
	if (L+1==R) return (s[L]=='[')?1:0;
	int get=(s[L]=='[')?1:0;
	for (int i=L+1;i<R;++i)
	{
		if (s[i]==')'||s[i]==']') return -MaxN;
		if (!way[i]||way[i]>R) return -MaxN;
		int tmp=check(i,way[i]);
		if (tmp==-MaxN) return -MaxN;
		get+=tmp;
		i=way[i];
	}
	return get;
}

void work()
{
	int ans=0,last=0;
	int begin,end,last_begin,last_end;
	for (int i=1,pre=0;i<=n;++i)
	{
		if (s[i]==')'||s[i]==']')
		{
			pre=0;
			continue;
		}
		if (!way[i])
		{
			pre=0;
			continue;
		}
		int get=check(i,way[i]);
		if (get>=0)
		{
			if (pre)
			{
				last+=get;
				last_end=way[i];
				if (ans<last)
				{
					ans=last;
					begin=last_begin;
					end=last_end;
				}
			}
			else
			{
				last=get;
				last_begin=i;
				last_end=way[i];
				if (ans<get)
				{
					ans=get;
					begin=i;
					end=way[i];
				}
			}
			pre=1;
			i=way[i];
		}
		else
			pre=0;
	}
	cout<<ans<<endl;
	if (ans==0) return;
	for (int i=begin;i<=end;++i)
		putchar(s[i]);
	puts("");
}

int main()
{
	init();
	work();
	return 0;
}