#pragma comment(linker,"/STACK:64000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int A[1004][1004];
struct point
{
	si i,j;
	point(){}
	point(si a,si b)
	{
		i=a;
		j=b;
	}
};

char I[3]={-1,0,1};
char J[3]={-1,0,1};
char dX[4]={-1,0,1,0};
char dY[4]={0,-1,0,1};



int sameCnt(point a)
{
	int cnt=0;
	for (int i=0;i<4;i++)
		if (A[a.i+dX[i]][a.j+dY[i]]==A[a.i][a.j])
			++cnt;
	return cnt;
}

vector<point> okr;
vector<point> all;
int mark;
bool ok;
void dfs(si i,si j)
{
	A[i][j]=mark;
	for (int ki=0;ki<3;ki++)
		for (int kj=0;kj<3;kj++)
		{
			if (A[i+I[ki]][j+J[kj]]==-1)
				ok=0;
			if (A[i+I[ki]][j+J[kj]]==0)
				dfs(i+I[ki],j+J[kj]);
			if (A[i+I[ki]][j+J[kj]]==1)
				all.push_back(point(i+I[ki],j+J[kj]));
		}
}

bool isOkr(si ai,si aj)
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (A[ai+I[i]][aj+J[j]]==mark)
				return true;
	return false;
}

void dfs2(si ai,si aj)
{
	A[ai][aj]=mark+1;
	okr.push_back(point(ai,aj));
	for (int i=0;i<4;i++)
		if (A[ai+dX[i]][aj+dY[i]]==1 && isOkr(ai+dX[i],aj+dY[i]))
			dfs2(ai+dX[i],aj+dY[i]);
}

//int CNT;
//void dfs3(si i,si j)
//{
//	A[i][j]=mark+2;
//	CNT++;
//	rep(k,0,4)
//		if (A[i+dX[k]][j+dY[k]]==mark+1)
//			dfs3(i+dX[k],j+dY[k]);
//}

int getCnt()
{
	rep(i,0,all.size())
		if (A[all[i].i][all[i].j]!=mark+1)
			return 0;
	rep(i,0,okr.size())
		if (sameCnt(okr[i])!=2)
			return 0;
	return okr.size();
}

int main()
{
	int n,m;
	cin>>n>>m;
	char S[1001][1001];
	rep(i,0,n)
		scanf(" %s",S[i]);
	rep(i,0,n+2)
		A[i][0]=A[i][m+1]=-1;
	rep(j,0,m+2)
		A[0][j]=A[n+1][j]=-1;
	rep(i,1,n+1)
		rep(j,1,m+1)
			A[i][j]=S[i-1][j-1]-'0';
	all.reserve(1000001);
	okr.reserve(1000001);
	mark=3;
	int res=0;
	rep(i,1,n)
		rep(j,1,m)
			if (A[i][j]==1 && A[i+1][j]==1 && A[i][j+1]==1 && A[i+1][j+1]==1)
				res=4;
	rep(i,1,n+1)
		rep(j,1,m+1)
		{
			if (A[i][j]==0)
			{
				all.clear();
				okr.clear();
				ok=1;
				mark+=3;
				//CNT=0;
				dfs(i,j);
				if (!ok) continue;
				if (A[i-1][j]==1)
				{
					dfs2(i-1,j);
					//dfs3(i-1,j);
				}
				else
				{
					dfs2(i,j-1);
					//dfs3(i,j-1);
				}
				int t=getCnt();
				if (res<t) res=t;
				rep(i,0,okr.size())
					A[okr[i].i][okr[i].j]=1;
				rep(i,0,all.size())
					A[all[i].i][all[i].j]=1;
			}
		}
	printf("%d\n",res);
	
	return 0;
} 
/*

3 3
111
101
111

7 7
1111111
1000101
1000101
1000101
1000111
1000001
1111111

3 3
011
111
111

7 7
0111111
1100001
1011101
1010101
1011101
1000001
1111111

5 5
11111
10001
10101
11001
11111

4 5
11111
10101
10001
11111

11 10
1111111111
1000000011
1111111101
1111111101
1111111101
1100000011
1011111111
1011111111
1011111111
1100000001
1111111111
//66

5 5
11111
10101
11011
10101
11111

7 7
1111111
1011101
1100011
1101011
1100011
1011101
1111111

5 50
00000000000000000000000000000011111111000000000000
00000001111111111111111111111111111111000000000000
00000011000000000000000000000000000111000000000000
00000011111111111111111111111111111100000000000000
00000010100001111000000000001100011000000000000000
*/