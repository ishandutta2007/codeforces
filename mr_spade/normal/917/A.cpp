//#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=5007;
int n,step,out,cnt,ans;
char s[N];
signed main()
{
	register int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		step=0;out=0;cnt=0;
		for(j=i;j<=n;j++)
		{
			if(s[j]=='(')
				step++,out++;
			else if(s[j]==')')
			{
				step--;out--;
				if(step<0)
					break;
			}
			else
				step++,out--,cnt++;
			if(out<0)
				out=0;
			if(((j-i+1)&1)||out>0)
				continue;
			if(cnt*2>=step)
			{
				ans++;
				//fprintf(stderr,"%d %d\n",i,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}