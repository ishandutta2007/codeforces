#include<bits/stdc++.h>
#define re register
int to[410][1010],tn[410];
int dfn[410],low[410],sta[410],bl[410],ta,tt;
int n,m,l,tot;
bool in[410],ok;
char sc[210],sk[210],ss[210],sx[210];
void addE(re int x,re int y)
{//printf("***%d %d\n",x,y);
	to[x][++tn[x]]=y;
}
void dfs(re int a)
{
	low[a]=dfn[a]=++tot;
	sta[++ta]=a;
	in[a]=1;
	for(re int i=1;i<=tn[a];i++)
	{
		re int x=to[a][i];
		if(!dfn[x])dfs(x),low[a]=std::min(low[a],low[x]);
		else if(in[x])low[a]=std::min(low[a],dfn[x]);
	}//printf("a*%d %d %d\n",a,low[a],dfn[a]);
	if(low[a]==dfn[a])
	{
		tt++;
		do
		{
			re int x=sta[ta];
			in[x]=0;
			if(tt==bl[x^1])ok=0;
			bl[x]=tt;
		}while(sta[ta--]!=a);
	}
}
bool ST()
{
	memset(dfn,0,sizeof(dfn));
	memset(bl,0,sizeof(bl));
	tot=0;tt=0;ok=1;
	for(re int i=2;i<=2*n+1;i++)if(!dfn[i])dfs(i);
	//printf("^-^**%d\n",ok);
	return ok;
}
int cs[210],vs[210];
int main()
{
	re int x,y;
	scanf("%s",sc);
	l=strlen(sc);
	for(re int i=l-1;i>=0;i--)cs[i]=cs[i+1]|(sc[i]=='C'),vs[i]=vs[i+1]|(sc[i]=='V');
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%s%d%s",&x,sk+1,&y,sk+2);//printf("*i*%d %d %d\n",i,x,y);
		addE(x*2+(sk[1]=='C'),y*2+(sk[2]=='C'));
		addE(y*2+(sk[2]!='C'),x*2+(sk[1]!='C'));
		if((sk[1]=='C'&&sk[2]!='C')&&!vs[0]){puts("-1");return 0;}
		if((sk[1]=='V'&&sk[2]!='V')&&!cs[0]){puts("-1");return 0;}
	}
	scanf("%s",ss+1);
	if((!cs[0])||(!vs[0])){puts(ss+1);return 0;}
	for(re int i=1;i<=n;i++)ss[i]-='a';
	re int i1=1,mx=0;
	for(;i1<=n+1;i1++)
	{//printf("***%d\n",i1);
		if(i1>1)
		{
			if(sc[ss[i1-1]]=='C')addE(i1*2-2,i1*2-1);
			if(sc[ss[i1-1]]=='V')addE(i1*2-1,i1*2-2);
		}
		if(i1<=n)
		{
			if(!cs[ss[i1]+1])addE(i1*2+1,i1*2);
			if(!vs[ss[i1]+1])addE(i1*2,i1*2+1);
		}
		re bool xa=ST();
		if(i1<=n)
		{
			if(!cs[ss[i1]+1])tn[i1*2+1]--;
			if(!vs[ss[i1]+1])tn[i1*2]--;
		}
		if(xa)mx=i1;
	}
	if(!mx){puts("-1");return 0;}
	for(re int i=n;i>=mx;i--)
	{
		if(sc[ss[i]]=='C')tn[i*2]--;
		if(sc[ss[i]]=='V')tn[i*2+1]--;
	}
	for(re int i=1;i<mx;i++)sx[i]=ss[i]+'a';
	if(mx<=n){if(sc[ss[mx]+1]=='C')addE(mx*2,mx*2+1);
	if(sc[ss[mx]+1]=='V')addE(mx*2+1,mx*2);
	if(ST())sx[mx]=ss[mx]+'a'+1;
	else
	{
		if(sc[ss[mx]+1]=='C')tn[mx*2]--,addE(mx*2+1,mx*2);
		if(sc[ss[mx]+1]=='V')tn[mx*2+1]--,addE(mx*2,mx*2+1);
		for(re int ii=ss[mx]+2;ii<l;ii++)if(sc[ii]!=sc[ss[mx]+1]){sx[mx]=ii+'a';break;}
	}}
	for(re int i=mx+1;i<=n;i++)
	{
		if(sc[0]=='C')addE(i*2,i*2+1);
		if(sc[0]=='V')addE(i*2+1,i*2);
		if(ST())sx[i]='a';
		else
		{
			if(sc[0]=='C')tn[i*2]--,addE(i*2+1,i*2);
			if(sc[0]=='V')tn[i*2+1]--,addE(i*2,i*2+1);
			for(re int ii=1;ii<=l;ii++)if(sc[ii]!=sc[0]){sx[i]=ii+'a';break;}
		}
	}
	puts(sx+1);
	return 0;
}