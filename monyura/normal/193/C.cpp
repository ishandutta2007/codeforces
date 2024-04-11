#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


string genMask(int a)
{
	int A[4][4]={0};
	rep(i,0,4)
		rep(j,0,4)
			if (((a>>i)^(a>>j))&1)
				A[i][j]=1;
	string res;
	rep(i,0,4)
		rep(j,i+1,4)
			res=res+char(A[i][j]+'0');
	return res;
}

const int INF=1e9;
const double EPS=1e-9;
int gauss (double a[6][7],double ans[6]) 
{
	int n = 6;
	int m = 6;
 
	int where[6];
	memset(where,-1,sizeof(where));
	for (int col=0, row=0; col<m && row<n; ++col)
	{
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	rep(i,0,m)
		ans[i]=0;
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return -1;
	return 1;
}

void run()
{
	const int Cnt=7;
	int M[Cnt]={1,2,4,8,9,5,3};
	int MA[7][6];
	rep(i,0,Cnt)
	{
		//printf("%d\n",M[i]);
		string curr=genMask(M[i]);
		rep(j,0,6)
			MA[i][j]=curr[j]-'0';
		//printf("%s\n",curr.c_str());
	}
	double A[6][7];
	
	int B[6];
	rep(i,0,6)
		scanf("%d",B+i);
	int Best[7];
	int bestSum=INF;
	double Curr[7];
	int st=INF;
	rep(i,0,6)
		if (MA[6][i])
			st=min(st,B[i]);
	int Calc[7];
	for (int a=0;a<=st;++a)
	{
		memset(A,0,sizeof(A));
		rep(i,0,6)
			rep(j,0,6)
				A[j][i]=MA[i][j];
		rep(i,0,6)
			A[i][6]=B[i];
		int res=gauss(A,Curr);
		if (res==1)
		{
			bool allOk=1;
			Calc[6]=a;
			rep(i,0,6)
				if (Curr[i]>-EPS)
				{
					Calc[i]=Curr[i]+EPS;
					if (fabs(Calc[i]-Curr[i])>EPS)
						allOk=0;
				}
				else
					allOk=0;
			if (allOk)
			{
				int sum=0;
				rep(i,0,7)
					sum+=Calc[i];
				if (sum<bestSum)
				{
					bestSum=sum;
					memcpy(Best,Calc,sizeof(Best));
				}
			}
		}
		rep(i,0,6)
			if (MA[6][i])
				B[i]--;
	}
	if (bestSum==INF)
		printf("-1\n");
	else
	{
		char Res[4][1000002]={0};
		int cnt=0;
		rep(i,0,7)
			rep(j,0,Best[i])
			{
				rep(k,0,4)
					Res[k][cnt]=((M[i]>>k)&1) + 'a';
				++cnt;
			}
		printf("%d\n",bestSum);
		rep(i,0,4)
			printf("%s\n",Res[i]);
	}
}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
	//generate();
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/