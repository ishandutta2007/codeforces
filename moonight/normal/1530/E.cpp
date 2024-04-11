#include<bits/stdc++.h>
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
const int N=100005;
int n,cc,c[30];char s[N]; 
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);cc=0;
		rep0(i,0,26)c[i]=0;
		rep(i,1,n)c[s[i]-'a']++;
		rep0(i,0,26)if(c[i])cc++;
		if(cc==1)//f(t)=n-1
		{
			rep(i,1,n)putchar(s[i]);
			rep(i,1,n)s[i]=0;
			puts("");continue;
		}
		rep(i,1,n)s[i]=0;
		int mn=n;
		rep0(i,0,26)if(c[i])mn=std::min(mn,c[i]);
		if(mn==1)//f(t)=0
		{
			rep0(i,0,26)if(c[i]==1)
			{
				putchar('a'+i);
				rep0(j,0,26)if(j!=i)
				{
					rep(t,1,c[j])putchar('a'+j);
				}
				break;
			}
			puts("");continue;
		}
		//f(t)=1
		int c1=-1,c2=-1,c3=-1;
		rep0(i,0,26)if(c[i]&&c1==-1)c1=c2,c2=c3,c3=i;
		if(c1==-1)c1=c2,c2=c3,c3=-1;
		int p=c[c1];
		if(p<=n-p+2)
		{
			putchar('a'+c1);putchar('a'+c1);
			c[c1]=0;
			rep(i,1,p-2)
			{
				rep0(j,0,26)if(c[j])
				{
					c[j]--;putchar('a'+j);break;
				}
				putchar('a'+c1); 
			}
			rep0(j,0,26)rep(t,1,c[j])putchar('a'+j);
			puts("");continue;
		}
		if(cc==2)
		{
			putchar('a'+c1);
			rep(t,1,c[c2])putchar('a'+c2);
			rep(t,1,c[c1]-1)putchar('a'+c1);
			puts("");continue;
		}
		putchar('a'+c1);putchar('a'+c2);
		rep(t,1,c[c1]-1)putchar('a'+c1);
		putchar('a'+c3);c[c3]--;
		rep(t,1,c[c2]-1)putchar('a'+c2);
		c[c1]=c[c2]=0;
		rep0(j,0,26)rep(t,1,c[j])putchar('a'+j);
		puts("");
	}
	return 0;
}