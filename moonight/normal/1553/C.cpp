#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
char s[15];
int main()
{
	int T=rd();
	while(T--)
	{
		scanf("%s",s+1);
		int ff=0;
		rep(i,1,9)
		{
			if(!ff)
			{
				int s1=0,s2=0;
				rep(j,1,i)if((j&1)&&s[j]!='0')s1++;
				rep(j,1,i)if((~j&1)&&s[j]=='1')s2++;
				rep(j,i+1,10)if(~j&1)s2++;
				if(s1>s2){printf("%d\n",i);ff=1;} 
			}
			if(!ff)
			{
				int s1=0,s2=0;
				rep(j,1,i)if((j&1)&&s[j]=='1')s1++;
				rep(j,1,i)if((~j&1)&&s[j]!='0')s2++;
				rep(j,i+1,10)if(j&1)s1++;
				if(s1<s2){printf("%d\n",i);ff=1;} 
			}
		}
		if(!ff)puts("10");
	}
    return 0;
}