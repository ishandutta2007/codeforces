#include<iostream>
using namespace std;
string S;
int dp[2020][2020];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>S;
		for(int i=0;i<S.size();i++)dp[i][i]=0;
		for(int k=2;k<=S.size();k+=2)for(int i=0;i+k<=S.size();i++)
		{
			int l=i,r=i+k;
			bool win=false,draw=false;
			for(int x:{l,r-1})
			{
				int nl=l,nr=r;
				if(x==l)nl++;
				else nr--;
				bool lose=false,drawn=false;
				for(int y:{nl,nr-1})
				{
					int nnl=nl,nnr=nr;
					if(y==nl)nnl++;
					else nnr--;
					int t=dp[nnl][nnr];
					if(t<0)lose=true;
					else if(t==0)
					{
						if(S[x]>S[y])lose=true;
						else if(S[x]==S[y])drawn=true;
					}
				}
				if(!lose)
				{
					if(drawn)draw=true;
					else win=true;
				}
			}
			if(win)dp[l][r]=1;
			else if(draw)dp[l][r]=0;
			else dp[l][r]=-1;
		}
		int t=dp[0][S.size()];
		cout<<(t>0?"Alice":t==0?"Draw":"Bob")<<"\n";
	}
}