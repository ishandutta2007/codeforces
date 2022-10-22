#include <iostream>
#include <algorithm>
//#include <cmath>//what the fuck that y1 has been used.
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
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
set <string> poke;
int n,m;
string rank[15]={"A","2","3","4","5","6","7","8","9","T","J","Q","K"};
string suit[5]={"C","D","H","S"};
string joke[5]={"J1","J2"};
string c[55][55];
vector <pii> vec;
bool ok[55][55];
map <string,int> suitid;
map <string,int> rankid;
int x1,y1,x2,y2;
string ph;
string J1,J2;

bool check_suit(int x,int y)
{
	int mask=0;
	for(int i=x;i<x+3;i++)
	{
		for(int j=y;j<y+3;j++)
		{
			mask|=suitid[c[i][j]];
		}
	}
	for(int i=0;i<4;i++)
	{
		if(mask==(1<<i)) return true;
	}
	return false;
}

bool check_rank(int x,int y)
{
	set <string> appear;
	appear.clear();
	for(int i=x;i<x+3;i++)
	{
		for(int j=y;j<y+3;j++)
		{
			appear.insert(c[i][j].substr(0,1));
		}
	}
	return (appear.size()==9);
}

bool overlap(int a,int b,int c,int d)
{
//	cout<<(abs(a-c)>=3)<<' '<<b-d<<endl;
	bool x=(abs(a-c)>=3);
	bool y=(abs(b-d)>=3);
//	cout<<(x||y)<<endl;
	return (!(x || y));
}

bool check()
{
	//put the first square.
	memset(ok,false,sizeof(ok));
	for(int i=0;i<n-2;i++)
	{
		for(int j=0;j<m-2;j++)
		{
			ok[i][j]=(check_suit(i,j) || check_rank(i,j));
		}
	}
//	cout<<(check_suit(0,3))<<' '<<check_rank(0,3)<<endl;
	for(int i=0;i<n-2;i++)
	{
		for(int j=0;j<m-2;j++)
		{
			for(int i2=0;i2<n-2;i2++)
			{
				for(int j2=0;j2<m-2;j2++)
				{
					if(overlap(i,j,i2,j2)) continue;
					if(ok[i][j] && ok[i2][j2])
					{
						x1=i;
						y1=j;
						x2=i2;
						y2=j2;
//						cout<<i<<'-'<<j<<' '<<i2<<'-'<<j2<<endl;
						return true;
					}
				}
			}
		}
	}
	return false;
}

void print()
{
	if(vec.size()==1)
	{
		printf("Solution exists.\n");
		cout<<"Replace "<<J1<<" with "<<c[vec[0].first][vec[0].second]<<"."<<endl;
		printf("Put the first square to (%d, %d).\n",x1+1,y1+1);
		printf("Put the second square to (%d, %d).\n",x2+1,y2+1);
//		printf("Replace J1 with ")
	}
	else if(J1=="J1")
	{
		printf("Solution exists.\n");
		cout<<"Replace J1 with "<<c[vec[0].first][vec[0].second];
		cout<<" and J2 with "<<c[vec[1].first][vec[1].second]<<".\n";
//		cout<<"Replace J2 with "<<c[vec[1].first][vec[1].second]<<endl;
		printf("Put the first square to (%d, %d).\n",x1+1,y1+1);
		printf("Put the second square to (%d, %d).\n",x2+1,y2+1);
	}
	else
	{
		printf("Solution exists.\n");
		cout<<"Replace J1 with "<<c[vec[1].first][vec[1].second];
		cout<<" and J2 with "<<c[vec[0].first][vec[0].second]<<".\n";
//		cout<<"Replace J2 with "<<c[vec[1].first][vec[1].second]<<endl;
		printf("Put the first square to (%d, %d).\n",x1+1,y1+1);
		printf("Put the second square to (%d, %d).\n",x2+1,y2+1);
	}
}

void dfs(int k)
{
//	cout<<vec.size()<<endl;
	if(k==vec.size())
	{
		if(check())
		{
			print();
			exit(0);
		}
		return;
	}
	int p1=vec[k].first,p2=vec[k].second;
	string temp;
	for(set <string> :: iterator it=poke.begin();it!=poke.end();it++)
	{
		if(c[vec[0].first][vec[0].second]==(*it)) continue;
//		cout<<c[vec[0].first][vec[0].second]<<' '<<*it<<endl;
//		cout<<(*it)<<'-'<<(ph)<<endl;
//		if((*it)==ph) continue;
//		cout<<ph<<endl;
//		if(k==2) 
//		{
//			cout<<*it<<endl;
//		}
		temp=c[p1][p2];
		c[p1][p2]=*it;
//		cout<<c[vec[0].first][vec[0].second]<<' '<<c[vec[1].first][vec[1].second]<<endl;
//		if(k==0) ph=*it;
//		poke.erase(*it);
		dfs(k+1);
//		if(k==0) ph="";
//		poke.insert(*it);
		c[p1][p2]=temp;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	for(int i=0;i<13;i++)
	{
		rankid[rank[i]]=i;
	}
	for(int i=0;i<4;i++)
	{
		suitid[suit[i]]=i;
	}
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<4;j++)
		{
			poke.insert(rank[i]+suit[j]);
		}
	}
//	for(int i=0;i<2;i++)
//	{
//		poke.insert(joke[i]);
//	}
	cin>>n>>m;
//	vec.push_back(mp(-1,-1));
//	vec.push_back(mp(-1,-1));
//	int s=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j];
			if(c[i][j][0]=='J' && isdigit(c[i][j][1]))
			{
				if(vec.size())
				{
					J2=c[i][j];
				}
				else
				{
					J1=c[i][j];
				}
//				vec[c[i][j][1]-'1']=
				vec.push_back(mp(i,j));
			}
//			s+=(c[i][j][0]=='J');
			poke.erase(c[i][j]);
		}
	}
	if(vec.size()==0)
	{
		if(check())
		{
			cout<<"Solution exists.\n";
			cout<<"There are no jokers.\n";
			printf("Put the first square to (%d, %d).\n",x1+1,y1+1);
			printf("Put the second square to (%d, %d).\n",x2+1,y2+1);
		}
		else
		{
			cout<<"No solution.\n";
		}
		return 0;
	}
	dfs(0);
	cout<<"No solution.\n";
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i].first<<' '<<vec[i].second<<endl;
//	}
//	cout<<check()<<endl;
	return 0;
}