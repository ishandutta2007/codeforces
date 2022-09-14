#include<cstdio>
using namespace std;
int T,N,K;
char S[3<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d\n%s",&N,&K,S);
		bool ok=true;
		for(int i=0;i<K;i++)
		{
			int wi=2;
			bool out=false;
			for(int j=i;j<N;j+=K)
			{
				if(S[j]=='1')
				{
					if(wi==1||wi==2)wi=1;
					else out=true;
				}
				else if(S[j]=='0')
				{
					if(wi==0||wi==2)wi=0;
					else out=true;
				}
			}
			if(out)
			{
				ok=false;
				break;
			}
			if(wi!=2)
			{
				for(int j=i;j<N;j+=K)if(S[j]=='?')S[j]=wi+'0';
			}
		}
		if(!ok)
		{
			puts("NO");
			continue;
		}
		int cnt=0,q=0;
		for(int i=0;i<K;i++)
		{
			if(S[i]=='0')cnt++;
			else if(S[i]=='1')cnt--;
			else q++;
		}
		if(cnt<0)cnt=-cnt;
		puts(cnt>q?"NO":"YES");
	}
}