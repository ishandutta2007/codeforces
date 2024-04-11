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
//#define x first
//#define y second

const double PI=acos(-1.0);
pii T[2000],P[2000];
int t=0,p=0,k;
vector<int> K[2000];


ll getSum(int cnt)
{
	if (cnt>k || cnt>t || k-cnt>p) return -1;
	ll dis=0;
	int st=0,sp=0;
	int top=p-(k-cnt);
	//if ((t+top)<2*cnt) return -1;
	int pos=cnt;
	rep(i,0,k)
		K[i].clear();
	rep(i,top,p)
		K[pos++].push_back(P[i].second);
	rep(i,0,cnt)
	{
		int curr=T[st].first;
		K[i].push_back(T[st].second);
		if (sp<top && P[sp].first>T[st].first)
		{
			curr=min(curr,P[sp].first);
			K[i].push_back(P[sp].second);
			sp++;
		}
		st++;
		if (i==k-1)
		{
			rep(j,st,t)
			{
				curr=min(curr,T[j].first);
				K[i].push_back(T[j].second);
			}
			rep(j,sp,top)
			{
				curr=min(curr,P[j].first);
				K[i].push_back(P[j].second);
			}
		}
		dis+=curr;
	}
	if (cnt!=k)
	{
		rep(j,st,t)
			K[k-1].push_back(T[j].second);
		rep(j,sp,top)
			K[k-1].push_back(P[j].second);
	}
	return dis;
}

int main()
{
	int n;
	cin>>n>>k;
	ll sum=0;
	rep(i,0,n)
	{
		int c,typ;
		scanf("%d%d",&c,&typ);
		sum+=c;
		if (typ==1) T[t++]=pii(c,i);
		else P[p++]=pii(c,i);
	}
	sort(T,T+t,greater<pii>());
	sort(P,P+p,greater<pii>());
	ll mx=-1;
	int cnt=-1;
	rep(i,0,k+1)
	{
		ll res=getSum(i);
		if (res>mx)
		{
			mx=res;
			cnt=i;
		}
	}
	ll dis=getSum(cnt);
	printf("%.1lf\n",sum-dis/2.0);
	rep(i,0,k)
	{
		printf("%d ",(int)K[i].size());
		rep(j,0,K[i].size())
			printf("%d ",K[i][j]+1);
		printf("\n");
	}
	return 0;
} 

/*


*/