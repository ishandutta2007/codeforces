#include<cstdio>
using namespace std;
int L[1<<17][2],R[1<<17][2];
int N,K;
char S[1<<17];
void fst(){puts("tokitsukaze");}
void snd(){puts("quailty");}
main()
{
	scanf("%d%d%s",&N,&K,S);
	L[0][0]=L[0][1]=-1;
	for(int i=0;i<N;i++)
	{
		L[i+1][0]=L[i][0];
		L[i+1][1]=L[i][1];
		L[i+1][S[i]-'0']=i;
	}
	R[N][0]=R[N][1]=N;
	for(int i=N;i--;)
	{
		R[i][0]=R[i+1][0];
		R[i][1]=R[i+1][1];
		R[i][S[i]-'0']=i;
	}
	for(int i=0;i+K<=N;i++)
	{
		if(L[i][0]==-1&&R[i+K][0]==N)
		{
			fst();
			return 0;
		}
		if(L[i][1]==-1&&R[i+K][1]==N)
		{
			fst();
			return 0;
		}
	}
	bool win=true;
	for(int i=0;i+K<=N;i++)
	{
		if(L[i][0]!=-1&&R[i+K][0]!=N)win=false;
		else if(L[i][0]==-1)
		{
			int l=R[i+K][0],r=L[N][0];
			if(r-l+1>K)win=false;
		}
		else if(R[i+K][0]==N)
		{
			int l=R[0][0],r=L[i][0];
			if(r-l+1>K)win=false;
		}
		if(L[i][1]!=-1&&R[i+K][1]!=N)win=false;
		else if(L[i][1]==-1)
		{
			int l=R[i+K][1],r=L[N][1];
			if(r-l+1>K)win=false;
		}
		else if(R[i+K][1]==N)
		{
			int l=R[0][1],r=L[i][1];
			if(r-l+1>K)win=false;
		}
	}
	if(win)snd();
	else puts("once again");
}