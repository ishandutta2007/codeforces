#pragma comment(linker,"/STACK:62000000")
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
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> inline T SQR(T a){return a*a;}

char A[9][9];
char R[9][9];
int best=0;
int n,m;
int row[4]={0,1,2,1};
int col[4]={1,2,1,0};

void rec(int x,int y,int cnt,char c)
{
	if (cnt>best)
	{
		best=cnt;
		memcpy(R,A,sizeof(R));
	}
	if ((n-1-x)*m+y<(best-cnt)*5) return;
	if (x>n-1 || y>m-1) return;
	bool was=0;
	if (x+3<=n && y+3<=m)
		rep(i,0,4)
		{
			bool ok=1;
			rep(j,0,3)
				if (A[x+row[i]][y+j]!='.' || A[x+j][y+col[i]]!='.')
				{
					ok=0;
					break;
				}
			if (ok)
			{
				was=1;
				rep(j,0,3)
					A[x+j][y+col[i]]=A[x+row[i]][y+j]=c;
				if (y+4>=m)
					rec(x+1,0,cnt+1,c+1);
				else
					rec(x,y+2,cnt+1,c+1);
				rep(j,0,3)
					A[x+j][y+col[i]]=A[x+row[i]][y+j]='.';
			}
		}
	if (y+3>=m)
		rec(x+1,0,cnt,c);
	else
		rec(x,y+1,cnt,c);
}

int main()
{
	memset(A,'.',sizeof(A));
	memset(R,'.',sizeof(R));
	cin>>n>>m;
	rec(0,0,0,'A');
	cout<<best<<endl;
	rep(i,0,n)
	{
		rep(j,0,m)
			putchar(R[i][j]);
		printf("\n");
	}
	return 0;
} 

/*
3 3
744477744 77747444 447744444

*/