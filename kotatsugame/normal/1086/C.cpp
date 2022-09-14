#include<cstdio>
#include<cstring>
using namespace std;
int T,K;
char S[1<<20],A[1<<20],B[1<<20];
int mp[256],inv[256];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s%s%s",&K,S,A,B);
		int N=strlen(S);
		{
			for(int i=0;i<K;i++)mp[i+'a']=inv[i+'a']=-1;
			bool lb=false,ok=false;
			for(int i=0;i<=N;i++)
			{
				if(i==N)
				{
					ok=true;
					break;
				}
				if(mp[S[i]]!=-1)
				{
					if(lb)
					{
						if(A[i]<mp[S[i]])
						{
							ok=true;
							break;
						}
						else if(A[i]>mp[S[i]])
						{
							break;
						}
					}
					else
					{
						if(A[i]>mp[S[i]]||B[i]<mp[S[i]])break;
						else if(A[i]<mp[S[i]]&&mp[S[i]]<B[i])
						{
							ok=true;
							break;
						}
						else if(mp[S[i]]<B[i])lb=true;
					}
				}
				else if(lb)
				{
					for(char c=A[i]+1;c<'a'+K;c++)if(inv[c]==-1)
					{
						mp[S[i]]=c;
						inv[c]=S[i];
						ok=true;
						break;
					}
					if(ok)break;
					if(inv[A[i]]!=-1)break;
					mp[S[i]]=A[i];
					inv[A[i]]=S[i];
				}
				else
				{
					for(char c=A[i]+1;c<B[i];c++)if(inv[c]==-1)
					{
						mp[S[i]]=c;
						inv[c]=S[i];
						ok=true;
						break;
					}
					if(ok)break;
					if(inv[A[i]]!=-1)break;
					mp[S[i]]=A[i];
					inv[A[i]]=S[i];
					if(mp[S[i]]<B[i])lb=true;
					else if(B[i]<mp[S[i]])break;
				}
			}
			if(ok)
			{
				int invi='a';
				for(int i=0;i<K;i++)if(mp[i+'a']==-1)
				{
					while(inv[invi]!=-1)invi++;
					mp[i+'a']=invi;
					inv[invi]=i+'a';
				}
				puts("YES");
				for(int i=0;i<K;i++)putchar(mp[i+'a']);
				puts("");
				continue;
			}
		}
		{
			for(int i=0;i<K;i++)mp[i+'a']=inv[i+'a']=-1;
			bool ua=false,ok=false;
			for(int i=0;i<=N;i++)
			{
				if(i==N)
				{
					ok=true;
					break;
				}
				if(mp[S[i]]!=-1)
				{
					if(ua)
					{
						if(mp[S[i]]<B[i])
						{
							ok=true;
							break;
						}
						else if(mp[S[i]]>B[i])
						{
							break;
						}
					}
					else
					{
						if(A[i]>mp[S[i]]||B[i]<mp[S[i]])break;
						else if(A[i]<mp[S[i]]&&mp[S[i]]<B[i])
						{
							ok=true;
							break;
						}
						else if(A[i]<mp[S[i]])ua=true;
					}
				}
				else if(ua)
				{
					for(char c='a';c<B[i];c++)if(inv[c]==-1)
					{
						mp[S[i]]=c;
						inv[c]=S[i];
						ok=true;
						break;
					}
					if(ok)break;
					if(inv[B[i]]!=-1)break;
					mp[S[i]]=B[i];
					inv[B[i]]=S[i];
				}
				else
				{
					for(char c=A[i]+1;c<B[i];c++)if(inv[c]==-1)
					{
						mp[S[i]]=c;
						inv[c]=S[i];
						ok=true;
						break;
					}
					if(ok)break;
					if(inv[B[i]]!=-1)break;
					mp[S[i]]=B[i];
					inv[B[i]]=S[i];
					if(A[i]<mp[S[i]])ua=true;
					else if(mp[S[i]]<A[i])break;
				}
			}
			if(ok)
			{
				int invi='a';
				for(int i=0;i<K;i++)if(mp[i+'a']==-1)
				{
					while(inv[invi]!=-1)invi++;
					mp[i+'a']=invi;
					inv[invi]=i+'a';
				}
				puts("YES");
				for(int i=0;i<K;i++)putchar(mp[i+'a']);
				puts("");
				continue;
			}
		}
		puts("NO");
	}
}