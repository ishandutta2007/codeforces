#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

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
typedef vector<pii> vp;

const double PI=acos(-1.0);

vp BUFF[200100];
int bpos=0;

int Val[200200];
int who[200200];
int key[200200];
int pos=0;

void proc(map<int,vp*> &mp,int cnt,int id)
{
	for (map<int,vp*>::iterator it=mp.begin();it!=mp.end();++it)
	{
		(it->second)->push_back(pii(cnt,cnt));
		int last = 0;
		vp &vec = *(it->second);
		sort(all(vec));
		int curr = 0;
		rep(i,0,vec.size())
		{
			pii p = vec[i];
			if (p.first>last)
			{
				curr+=p.first-last;
			}
			last = max(last,p.second);
		}
		Val[pos] = curr;
		who[pos] = id;
		key[pos] = it->first;
		pos++;
	}
}

int findAns(map<int,vp*> &mp,int win,int need)
{
	int ans = -1;
	int last = 0;
	vp &vec = *mp[key[win]];
	int has=0;
	rep(i,0,vec.size())
	{
		pii p=vec[i];
		if (p.first>last)
		{
			int currLen = has + p.first - last;
			if (currLen>=need)
			{
				ans = last + (need-has);
				break;
			}
			has = currLen;
		}
		last=max(last,p.second);
	}
	return ans;
}

void run()
{
	map<int,vp*> hor;
	map<int,vp*> ver;
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,0,k)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1==x2)
		{
			if (x1==0 || x1==n) continue;
			if (hor.find(x1)==hor.end())
			{
				hor[x1] = BUFF+bpos;
				bpos++;
			}
			if (y1>y2) swap(y1,y2);
			hor[x1]->push_back(pii(y1,y2));
		}
		else
		{
			if (y1==0 || y1==m) continue;
			if (ver.find(y1)==ver.end())
			{
				ver[y1] = BUFF+bpos;
				bpos++;
			}
			if (x1>x2) swap(x1,x2);
			ver[y1]->push_back(pii(x1,x2));
		}
	}
	if (hor.size() < n && ((n-1-hor.size())&1))
	{
		rep(i,1,n)
			if (hor.find(i)==hor.end())
			{
				hor[i] = BUFF+bpos;
				bpos++;
				break;
			}
	}
	if (ver.size() < m && ((m-1-ver.size())&1))
	{
		rep(i,1,m)
			if (ver.find(i)==ver.end())
			{
				ver[i] = BUFF+bpos;
				bpos++;
				break;
			}
	}
	proc(hor,m,0);
	proc(ver,n,1);
	int res = 0;
	rep(i,0,pos)
		res^=Val[i];
	if (res==0)
		puts("SECOND");
	else
	{
		puts("FIRST");
		int win = -1;
		int need = -1;
		rep(i,0,pos)
		{
			int left = Val[i]^res;
			if (left<Val[i])
			{
				win = i;
				need = Val[i] - left;
				break;
			}
		}
		if (who[win]==0)
		{
			int ans = findAns(hor,win,need);
			printf("%d %d %d %d\n",key[win],0,key[win],ans);
		}
		else
		{
			int ans = findAns(ver,win,need);
			printf("%d %d %d %d\n",0,key[win],ans,key[win]);
		}
	}
	

}





int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/