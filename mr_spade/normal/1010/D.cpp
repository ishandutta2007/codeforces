#include<cstdio>
#include<cctype>
const int N=1e6+5;
inline int read()
{
	int res=0;
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		res=res*10+x-'0';
	return res;
}
inline int readtype()
{
	char x;
	while(!isgraph(x=getchar()));
	switch(x)
	{
		case 'A':return 1;
		case 'O':return 2;
		case 'X':return 3;
		case 'N':return 4;
		case 'I':return 5;
	}
}
int n;
int op[N],l[N],r[N],k[N];
int ans[N];
void dfs(int now)
{
	if(op[now]==5)
	{
		k[now]=l[now];
		return;
	}
	if(op[now]==4)
	{
		dfs(l[now]);
		k[now]=!k[l[now]];
		return;
	}
	dfs(l[now]);dfs(r[now]);
	switch(op[now])
	{
		case 1:k[now]=k[l[now]]&k[r[now]];break;
		case 2:k[now]=k[l[now]]|k[r[now]];break;
		case 3:k[now]=k[l[now]]^k[r[now]];break;
	}
	return;
}
void dfs2(int now,int ca)
{
	if(op[now]==5)
	{
		if(ca==1)
			ans[now]=!k[now];
		else if(ca==2)
			ans[now]=k[now];
		else
			ans[now]=k[1];
		return;
	}
	if(op[now]==4)
	{
		if(ca==1)
			dfs2(l[now],2);
		else if(ca==2)
			dfs2(l[now],1);
		else
			dfs2(l[now],3);
		return;
	}
	if(ca==3)
	{
		dfs2(l[now],3);
		dfs2(r[now],3);
		return;
	}
	if(ca==1)
	{
		switch(op[now])
		{
			case 1:
				if(!k[r[now]])
					dfs2(l[now],3);
				else
					dfs2(l[now],1);
				if(!k[l[now]])
					dfs2(r[now],3);
				else
					dfs2(r[now],1);
				break;
			case 2:
				if(k[r[now]])
					dfs2(l[now],3);
				else
					dfs2(l[now],1);
				if(k[l[now]])
					dfs2(r[now],3);
				else
					dfs2(r[now],1);
				break;
			case 3:
				if(k[r[now]])
					dfs2(l[now],2);
				else
					dfs2(l[now],1);
				if(k[l[now]])
					dfs2(r[now],2);
				else
					dfs2(r[now],1);
				break;
		}
		return;
	}
	switch(op[now])
	{
		case 1:
			if(!k[r[now]])
				dfs2(l[now],3);
			else
				dfs2(l[now],2);
			if(!k[l[now]])
				dfs2(r[now],3);
			else
				dfs2(r[now],2);
			break;
		case 2:
			if(k[r[now]])
				dfs2(l[now],3);
			else
				dfs2(l[now],2);
			if(k[l[now]])
				dfs2(r[now],3);
			else
				dfs2(r[now],2);
			break;
		case 3:
			if(k[r[now]])
				dfs2(l[now],1);
			else
				dfs2(l[now],2);
			if(k[l[now]])
				dfs2(r[now],1);
			else
				dfs2(r[now],2);
			break;
	}
	return;
}
signed main()
{
	register int i;
	n=read();
	for(i=1;i<=n;i++)
	{
		op[i]=readtype();
		if(op[i]<=3)
			l[i]=read(),r[i]=read();
		else
			l[i]=read();
	}
	dfs(1);
	dfs2(1,1);//1:you 2:not you 3:no deal
	for(i=1;i<=n;i++)
		if(op[i]==5)
			printf("%d",ans[i]);
	putchar('\n');
	return 0;
}