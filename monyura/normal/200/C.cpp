//#pragma comment(linker,"/STACK:128000000")
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

struct match
{
	int f;
	int s;
	int zab;
	int pr;
	match(){}
	match(int f0,int s0,int z,int p)
	{
		f=f0;
		s=s0;
		zab=z;
		pr=p;
	}
};

int Point[4]={0};
int Goal[4]={0};
int Prop[4]={0};

bool cmp(int a,int b)
{
	if (Point[a]!=Point[b])
		return Point[a]>Point[b];
	if (Goal[a]-Prop[a]!=Goal[b]-Prop[b])
		return Goal[a]-Prop[a]>Goal[b]-Prop[b];
	if (Goal[a]!=Goal[b])
		return Goal[a]>Goal[b];
	return a<b;
}
	

int place(match M[6],int team)
{
	rep(i,0,4)
		Goal[i]=Point[i]=Prop[i]=0;
	rep(i,0,6)
	{
		Goal[M[i].f]+=M[i].zab;
		Prop[M[i].f]+=M[i].pr;
		Goal[M[i].s]+=M[i].pr;
		Prop[M[i].s]+=M[i].zab;
		if (M[i].zab==M[i].pr)
		{
			Point[M[i].f]++;
			Point[M[i].s]++;
		}
		else if (M[i].zab>M[i].pr)
			Point[M[i].f]+=3;
		else
			Point[M[i].s]+=3;
	}
	int A[4]={0,1,2,3};
	sort(A,A+4,cmp);
	rep(i,0,4)
		if (A[i]==team)
			return i;
}

void getMatch(match M[6])
{
	char F[6][1000],S[6][1000];
	vector<string> vec;
	map<string,int> games;
	rep(i,0,5)
	{
		scanf(" %s %s %d:%d",F[i],S[i],&M[i].zab,&M[i].pr);
		vec.push_back(F[i]);
		vec.push_back(S[i]);
		games[F[i]]++;
		games[S[i]]++;
	}
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	string curr;
	rep(i,0,4)
		if (vec[i]!="BERLAND" && games[vec[i]]<3)
			curr=vec[i];
	map<string,int> mp;
	rep(i,0,4)
		mp[vec[i]]=i;
	rep(i,0,5)
	{
		M[i].f=mp[F[i]];
		M[i].s=mp[S[i]];
	}
	M[5].f=mp["BERLAND"];
	M[5].s=mp[curr];
}

void run()
{
	match M[6];
	getMatch(M);
	int x=-1,y=-1;
	rep(i,1,100)
		rep(j,0,i)
		{
			M[5].zab=i;
			M[5].pr=j;
			int pl=place(M,M[5].f);
			if (pl<=1 && (x==-1 || i-j<x-y  || i-j==x-y && j<y))
			{
				x=i;
				y=j;
			}
		}
	if (x==-1)
		printf("IMPOSSIBLE\n");
	else
		printf("%d:%d\n",x,y);
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t beg=clock();
#endif
	run();
#ifdef _MONYURA_
	printf("================\n");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/