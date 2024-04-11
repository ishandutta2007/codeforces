#pragma comment(linker,"/STACK:128000000")
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
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}



class cmp
{
public:
	int *A;
	cmp(int *B)
	{
		A=B;
	}
	cmp()
	{
		A=0;
	}
	bool operator()(int a,int b) const
	{
		return A[a]<A[b];
	}
};

void run()
{
	int n,m,h;
	cin>>h>>m>>n;
	int Cnt[200200]={0};
	int Gr[200200];
	int Ind[200200];
	int gCnt=0;
	bool was[200200]={0};
	int Val[200200];
	set<int,cmp> st[200200];
	rep(i,0,h)
		st[i].comp=cmp(Ind);

	rep(i,0,h)
		if (!was[i])
		{
			int curr=i;
			int ind=0;
			while (!was[curr])
			{
				was[curr]=1;
				Gr[curr]=gCnt;
				Ind[curr]=ind++;
				st[gCnt].insert(curr);
				Cnt[gCnt]++;
				curr+=m;
				if (curr>=h) curr-=h;
			}
			gCnt++;
		}
	set<int,cmp>::iterator it;
	ll res=0;
	char c;
	int id,hash;
	map<int,int> Where;
	map<int,int> H;
	rep(i,0,n)
	{
		scanf(" %c%d",&c,&id);
		if (c=='+')
		{
			scanf("%d",&hash);
			int gr=Gr[hash];
			it=st[gr].lower_bound(hash);
			int add=0;
			if (it==st[gr].end())
			{
				it=st[gr].lower_bound(0);
				add=Cnt[gr]-Ind[hash]+Ind[*it];
			}
			else
			{
				add=Ind[*it]-Ind[hash];
			}
			Where[id]=*it;
			st[gr].erase(it);
			H[id]=hash;
			res+=add;
		}
		else
		{
			int hash=H[id];
			int gr=Gr[hash];
			st[gr].insert(Where[id]);
		}
	}
	cout<<res<<endl;
}

int main()
{

#ifdef _MON_JUDGE_
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/