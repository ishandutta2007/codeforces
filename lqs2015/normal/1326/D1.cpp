#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,cnt,p[2222222],mx,id,pos,mxx,ps;
char s[1111111],ss[2222222];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		n=strlen(s);
		ss[cnt=0]='#';cnt=1;
		for (int i=0;i<n;i++)
		{
			ss[cnt++]=s[i];
			ss[cnt++]='#';
		}
		mx=id=0;
		for (int i=0;i<cnt;i++)
		{
			if (i<mx) p[i]=min(p[2*id-i],mx-i);
			else p[i]=0;
			while(i+p[i]+1<cnt && i-p[i]-1>=0 && ss[i+p[i]+1]==ss[i-p[i]-1])
			{
				p[i]++;
			} 
			if (i+p[i]>mx)
			{
				mx=i+p[i];
				id=i;
			}
		}
		pos=0;
		while(pos<=n-1-pos && s[pos]==s[n-1-pos]) pos++;
		pos--;
		if (pos>=n-1-pos) 
		{
			printf("%s\n",s);
			continue;
		}
		mxx=0;ps=0;
		for (int i=(pos+1)*2;i<=2*(n-pos)-2;i++)
		{
			if (i-p[i]-1<=(pos+1)*2-1 || i+p[i]+1>=2*(n-pos)-1) 
			{
				if (mxx<min(p[i],min(i-2*(pos+1),2*(n-pos)-2-i)))
				{
					mxx=min(p[i],min(i-2*(pos+1),2*(n-pos)-2-i));
					ps=i;
				}
			}
		}
		for (int i=0;i<=pos;i++) putchar(s[i]);
		if (mxx)
		{
			for (int i=ps-mxx;i<=ps+mxx;i++) 
			{
				if (ss[i]!='#') putchar(ss[i]);
			}
		}
		for (int i=n-pos-1;i<n;i++) putchar(s[i]);
		putchar('\n');
	}
	return Accepted;
}