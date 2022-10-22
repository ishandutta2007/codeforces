#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
bool dp[5][205][205][6];
pair<pii,int>track[5][205][205][5];
vector <int> i25;
vector <int> j25;
vector <int> i15;
vector <int> j15;

pair<int,int> max(pii a,pii b)
{
	if(a.first-a.second>b.first-b.second)
	{
		return a;
	}
	else
	{
		return b;
	}
}

const operator >(pii a,pii b)
{
	return a.first-a.second>b.first-b.second;
}

bool ok25(int x,int y)
{
	if(x==25 && y<=23) return true;
	if(y==25 && x<=23) return true;
	if(x>=24 && y>=24)
	{
		if(x==y+2 || y==x+2) return true;
	}
	return false;
}

bool ok15(int x,int y)
{
	if(x==15 && y<=13) return true;
	if(y==15 && x<=13) return true;
	if(x>=14 && y>=14)
	{
		if(x==y+2 || y==x+2) return true;
	}
	return false;
}

pii mix(pii a,int x,int y)
{
	if(x>y)
	{
		return mp(a.first+1,a.second);
	}
	else
	{
		return mp(a.first,a.second+1);
	}
}

int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<=200;j++)
		{
			for(int k=0;k<=200;k++)
			{
				for(int o=0;o<5;o++)
				{
					dp[i][j][k][o]=false;
				}
//				dp[i][j][k]=mp(0,inf);
			}
		}
	}
//	freopen("input.txt","r",stdin);
	for(int i=0;i<=200;i++)
	{
		for(int j=0;j<=200;j++)
		{
			if(!ok25(i,j)) continue;
			i25.push_back(i);
			j25.push_back(j);
		}
	}
	for(int i=0;i<=200;i++)
	{
		for(int j=0;j<=200;j++)
		{
			if(!ok15(i,j)) continue;
			i15.push_back(i);
			j15.push_back(j);
		}
	}
	for(int t=0;t<i25.size();t++)
	{
		int i=i25[t];
		int j=j25[t];
		if(i>j)
		{
			dp[0][i][j][1]=true;
			track[0][i][j][1]=mp(mp(0,0),0);
//			dp[0][i][j]=mp(1,0);
//			track[0][i][j]=mp(0,0);
		}
		else
		{
			dp[0][i][j][0]=true;
			track[0][i][j][0]=mp(mp(0,0),0);
//			dp[0][i][j]=mp(0,1);
//			track[0][i][j]=mp(0,0);
		}
	}
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<=200;i++)
		{
			for(int j=0;j<=200;j++)
			{
				for(int gwq=0;gwq<=k+1;gwq++)
				{
//					if(k<0 || i<0 || j<0 || gwq<0) over("FICL");
					if(dp[k][i][j][gwq]==false) continue;
					int xzm=k-gwq+1;
					if(xzm>=3 || gwq>=3) continue;
					for(int t=0;t<i25.size();t++)
					{
						int di=i25[t];
						int dj=j25[t];
						if(i+di>200) continue;
						if(j+dj>200) continue;
//						if(k+1<0 || i+di<0 || j+dj<0 || gwq+(di>dj)<0) over("FUCK");
						dp[k+1][i+di][j+dj][gwq+(di>dj)]=true;
						track[k+1][i+di][j+dj][gwq+(di>dj)]=mp(mp(i,j),gwq);
					}
				}
			}
		}
	}
//	cout<<dp[0][74][76][3]<<endl;
//	cout<<dp[1][80][100][]<<endl;
	for(int k=3;k<4;k++)
	{
		for(int i=0;i<=200;i++)
		{
			for(int j=0;j<=200;j++)
			{
				for(int gwq=0;gwq<=k+1;gwq++)
				{
					if(dp[k][i][j][gwq]==false) continue;
					int xzm=k-gwq+1;
					if(xzm>=3 || gwq>=3) continue;
					for(int t=0;t<i15.size();t++)
					{
						int di=i15[t];
						int dj=j15[t];
						if(i+di>200) continue;
						if(j+dj>200) continue;
						dp[k+1][i+di][j+dj][gwq+(di>dj)]=true;
						track[k+1][i+di][j+dj][gwq+(di>dj)]=mp(mp(i,j),gwq);
					}
				}
			}
		}
	}
//	cout<<dp[2][127][175][1]<<endl;
//	cout<<dp[3][65][89][2]<<endl;
//	cout<<dp[4][80][100][3]<<endl;
//	for(int k=3;k<4;k++)
//	{
//		for(int i=0;i<=200;i++)
//		{
//			for(int j=0;j<=200;j++)
//			{
//				for(int t=0;t<i15.size();t++)
//				{
//					int di=i15[t];
//					int dj=j15[t];
//					if(i+di>=200) continue;
//					if(j+dj>=200) continue;
//					if(max(dp[k][i][j].first,dp[k][i][j].second)>=3) continue;
////					if(max(mix(dp[k][i][j],di,dj).first,mix(dp[k][i][j],di,dj).second)>=3) continue;
//					if(mix(dp[k][i][j],di,dj)>dp[k+1][i+di][j+dj])
//					{
//						dp[k+1][i+di][j+dj]=mix(dp[k][i][j],di,dj);
//						track[k+1][i+di][j+dj]=mp(i,j);
//					}
////					dp[k][i+di][j+dj]=max(dp[k][i+di][j+dj],mix(dp[k][i][j],di,dj));
//				}
//			}
//		}
//	}
//	cout<<dp[2][75][27].first<<' '<<dp[2][75][27].second<<endl;
//	cout<<dp[0][75][0].first<<' '<<dp[0][75][0].second<<endl;
//	cout<<dp[1][50][0][2]<<endl;
//	cout<<dp[1][80][100][5];
//	cout<<dp[0][6][24][1];
//	return 0;
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		pair<int,int> res=mp(-1,-1);
//		int k=-1;
		for(int delta=3;delta>=-3;delta--)
		{
			for(int A=0;A<=5;A++)
			{
				int B=A-delta;
				if(A<3 && B<3) continue;
				if(B<0 || B>5) continue;
//				if(A==3 && B==2) cout<<delta<<' '<<A+B-1<<endl;
				for(int i=0;i<=4;i++)
				{
					if(i!=A+B-1) continue;
					if(dp[i][a][b][A])
					{
						res=mp(i,A);
						delta=-10;
						A=10;
						i=10;
						break;
					}
				}
			}
		}
		if(res==mp(-1,-1))
		{
			printf("Impossible\n");
		}
		else
		{
			vector <pair<int,int> > vec;
			printf("%d:%d\n",res.second,res.first+1-res.second);
			vec.clear();
			int k=res.first;//k=1,c=5
//			cout<<"K"<<' '<<k<<endl;
			int c=res.second;
			while(k>=0)
			{
				int na=track[k][a][b][c].first.first;
				int nb=track[k][a][b][c].first.second;
				int nc=track[k][a][b][c].second;
				vec.push_back(mp(a-na,b-nb));
				a=na;
				b=nb;
				c=nc;
				k--;
			}
			reverse(all(vec));
			for(int i=0;i<vec.size();i++)
			{
				printf("%d:%d ",vec[i].first,vec[i].second);
			}
			printf("\n");
		}
//		for(int i=0;i<=4;i++)
//		{
//			if(max(dp[i][a][b].first,dp[i][a][b].second)!=3) continue;
//			if(dp[i][a][b]>res)
//			{
//				k=i;
//				res=dp[i][a][b];
//			}
////			res=max(res,dp[i][a][b]);
//		}
//		cout<<"fuck"<<k<<endl;
//		if(res.first-res.second<=-10)
//		{
//			printf("Impossible\n");
//		}
//		else
//		{
//			printf("%d:%d\n",res.first,res.second);
//			vector <pair<int,int> > vec;
//			while(k>=0)
//			{
//				int nx=track[k][a][b].first,ny=track[k][a][b].second;
//				vec.push_back(mp(a-nx,b-ny));
//				a=nx;
//				b=ny;
//				k--;
//			}
////			cout<<vec.size()<<endl;
//			reverse(all(vec));
//			for(int i=0;i<vec.size();i++)
//			{
//				printf("%d:%d ",vec[i].first,vec[i].second);
//			}
//			printf("\n");
//		}
	}
	return 0;
}