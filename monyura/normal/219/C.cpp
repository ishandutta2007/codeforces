#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <functional>
#include <ctime>
#include <complex>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;++x)
#define all(a) (a).begin(),(a).end()

pii pmin(const pii &a,const pii &b)
{
	if (a.first<b.first)
		return a;
	return b;
}
int From[500500][26];
int main()
{
	//freopen("condoms.in", "r", stdin); freopen("condoms.out", "w", stdout);
	int n,k;
	cin>>n>>k;
	char str[500500];
	scanf(" %s",str);
	const int INF=1e9;
	pii pref[26],suf[26];
	rep(i,0,k)
		pref[i]=suf[i]=pii(INF,-1);
	pii Curr[26];
	rep(i,0,k)
		Curr[i]=pii(1,i);
	Curr[str[0]-'A']=pii(0,str[0]-'A');
	pref[0]=pii(INF,0);
	rep(i,1,k)
		pref[i]=pmin(pref[i-1],Curr[i-1]);
	suf[k-1]=pii(INF,k-1);
	for (int i=k-2;i>=0;i--)
		suf[i]=pmin(suf[i+1],Curr[i+1]);
	rep(i,0,k)
		From[0][i]=-1;
	rep(j,1,strlen(str))
	{
		rep(i,0,k)
		{
			Curr[i]=pmin(pref[i],suf[i]);
			From[j][i]=Curr[i].second;
			Curr[i].second=i;
			if (i!=str[j]-'A')
			{
				Curr[i].first++;
			}
		}
		pref[0]=pii(INF,0);
		rep(i,1,k)
			pref[i]=pmin(pref[i-1],Curr[i-1]);
		suf[k-1]=pii(INF,k-1);
		for (int i=k-2;i>=0;i--)
			suf[i]=pmin(suf[i+1],Curr[i+1]);
	}
	pii res=pii(INF,-1);
	rep(i,0,k)
		res=pmin(res,Curr[i]);
	int ind=res.second;
	char ans[500500]={0};
	for (int i=n-1;i>=0;i--)
	{
		ans[i]=ind+'A';
		ind=From[i][ind];
	}
	printf("%d\n%s\n",res.first,ans);
	return 0;
}