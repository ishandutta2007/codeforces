#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int H,W;
vector<vector<bool> >S;
vector<vector<int> >C;
vector<string>check(int T)
{
	vector<string>ret(H,string(W,'.'));
	vector<vector<int> >cum(H+1,vector<int>(W+1,0));
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(C[i][j]>=T*2+1)
	{
		ret[i+T][j+T]='X';
		cum[i][j]++;
		cum[i+2*T+1][j]--;
		cum[i][j+2*T+1]--;
		cum[i+2*T+1][j+2*T+1]++;
	}
	for(int i=0;i<=H;i++)for(int j=0;j<W;j++)cum[i][j+1]+=cum[i][j];
	for(int j=0;j<=W;j++)for(int i=0;i<H;i++)cum[i+1][j]+=cum[i][j];
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(S[i][j]?cum[i][j]==0:cum[i][j]!=0)
	{
		return (vector<string>){};
	}
	return ret;
}
main()
{
	scanf("%d%d\n",&H,&W);
	S=vector<vector<bool> >(H,vector<bool>(W));
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			char c;scanf("%c",&c);
			S[i][j]=c=='X';
		}
		scanf("\n");
	}
	C=vector<vector<int> >(H,vector<int>(W,0));
	for(int i=H;i--;)for(int j=W;j--;)
	{
		if(S[i][j])
		{
			int A=1e9;
			if(i+1<H)A=min(A,C[i+1][j]);
			else A=0;
			if(j+1<W)A=min(A,C[i][j+1]);
			else A=0;
			if(i+1<H&&j+1<W)A=min(A,C[i+1][j+1]);
			else A=0;
			C[i][j]=A+1;
		}
		else C[i][j]=0;
	}
	int L=0,R=min(H,W);
	while(R-L>1)
	{
		int mid=(L+R)/2;
		if(check(mid).empty())R=mid;
		else L=mid;
	}
	printf("%d\n",L);
	vector<string>ans=check(L);
	for(int i=0;i<H;i++)printf("%s\n",ans[i].c_str());
}