#pragma comment(linker,"/STACK:65000000")
#include <iostream>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const double PI = acos(-1.0);

const int mod=1e9;

//int S[1601][1601]={0};
//inline int getS(int x,int y)
//{
//	if (x<0 || y<0) return 0;
//	return S[x][y];
//}

int n,m;
int P[1601][1601];
int Id[1601][1601];

char Corners[1601][1601]={0};

int currId;
inline int Pix(int i,int j)
{
	return (i>=0 && i<n && j>=0 && j<m ? Id[i][j]==currId : 0);
}

vector<int> detectCorners()
{
	map<int,int> mp;
	const int sz=6;
	const int psz = 4;
	const int th = 2;
	rep(i,0,n)
		rep(j,0,m)
			if (P[i][j]==1 && Corners[i][j]!=2)
			{
				int cnt = 0;
				currId = Id[i][j];
				rep(a,0,sz)
					cnt+=Pix(i-1+a,j-1) + Pix(i-1,j-1+a);
				
				if (cnt>th)
				{
					cnt = 0;
					rep(a,0,sz)
						cnt+=Pix(i-1+a,j+1) + Pix(i-1,j+1-a);
					if (cnt>th)
					{
						cnt=0;
						rep(a,0,sz)
							cnt+=Pix(i+1-a,j+1) + Pix(i+1,j+1-a);
						if (cnt>th)
						{
							cnt = 0;
							rep(a,0,sz)
								cnt+=Pix(i+1-a,j-1)+Pix(i+1,j-1+a);
						}
					}
				}
				if (cnt<=th)
				{
					mp[Id[i][j]]++;
					rep(a,-psz,psz+1)
						rep(b,-psz,psz+1)
							if (Pix(i+a,j+b))
								Corners[i+a][j+b]=2;
				}
			}
	vector<int> res;
	for (map<int,int>::iterator iter = mp.begin();iter!=mp.end();++iter)
		res.push_back(iter->second);
	return res;

}

void run()
{
	cin>>n>>m;
	char str[10000];
	rep(i,0,n)
	{
		gets(str);
		int pos =0;
		rep(j,0,strlen(str))
			if (str[j]=='0' || str[j]=='1')
				P[i][pos++]=str[j]-'0';
	}
	int sz = 11;
	int hsz = sz/2;
	bool  was[1601][1601]={0};
	int dx[]={-1,0,1,0};
	int dy[]={0,-1,0,1};
	int lastId = 2;
	rep(i,0,n)
		rep(j,0,m)
			if (!was[i][j] && P[i][j]==1)
			{
				queue<pii> q;
				q.push(pii(i,j));
				was[i][j]=1;
				Id[i][j]=lastId;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					rep(k,0,4)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx>=0 && nx<n && ny>=0 && ny<m && !was[nx][ny] && P[nx][ny]==1)
						{
							was[nx][ny]=1;
							Id[nx][ny]=lastId;
							q.push(pii(nx,ny));
						}
					}
				}
				++lastId;
			}
	vector<int> res = detectCorners();
	sort(all(res));
	printf("%d\n",res.size());
	rep(i,0,res.size())
		printf("%d ",res[i]);
	if (res.size())
		puts("");

}


int main()
{
#ifdef _MONYURA_
	//freopen("test.in","r",stdin);
	freopen("sun/01.in.txt","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/