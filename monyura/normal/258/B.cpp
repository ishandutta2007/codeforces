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
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);


const int mod = 1000000007;

int D[10][10]={0};

void init()
{
	D[0][0]=1;
	rep(n,1,10)
	{
		rep(d,0,10)
		{
			if (d!=4 && d!=7)
			{
				D[n][0]+=D[n-1][0];
				rep(k,1,10)
					D[n][k]+=D[n-1][k];
			}
			else
			{
				rep(k,1,10)
					D[n][k]+=D[n-1][k-1];
			}
		}
	}
}

int calcCnt(int m,int need)
{
	char str[20];
	sprintf(str,"%d",m);
	int l = strlen(str);
	reverse(str,str+l);
	int res=0;
	int has=0;
	for (int i=l-1;i>=0;i--)
	{
		str[i]-='0';
		if (str[i]<=4)
			res+=str[i]*D[i][need-has];
		else if (str[i]<=7)//>=5
		{
			res+=4*D[i][need-has];
			if (need-has-1>=0)
				res+=D[i][need-has-1];
			res+=(str[i]-5)*D[i][need-has];
		}
		else
		{
			res+=4*D[i][need-has];
			if (need-has-1>=0)
				res+=D[i][need-has-1];
			res+=2*D[i][need-has];
			if (need-has-1>=0)
				res+=D[i][need-has-1];
			res+=(str[i]-8)*D[i][need-has];
		}
		if (str[i]==4 || str[i]==7)
			++has;
		if (has>need)
			break;
	}
	if (has==need)
		++res;
	return res;
}

ll res=0;

int Cnt[10];
void rec(int ind,int sum,int currsum,ll currcnt)
{
	if (ind==6)
	{
		if (currsum<sum)
			res=(res+currcnt)%mod;
		return;
	}
	rep(i,0,sum)
	{
		if (currsum+i<sum && Cnt[i]!=0)
		{
			ll was=Cnt[i];
			--Cnt[i];
			rec(ind+1,sum,currsum+i,(currcnt*was)%mod);
			++Cnt[i];
		}
	}
}


bool check(int m,int cnt)
{
	int calc = calcCnt(m,cnt);
	if (cnt==0)
		--calc;
	char str[20];
	int res=0;
	rep(i,1,m+1)
	{
		sprintf(str,"%d",i);
		int curr=0;
		rep(j,0,strlen(str))
			if (str[j]=='4' || str[j]=='7')
				++curr;
		res+=(curr==cnt);
	}
	return calc == res;
}

void run()
{	
	init();
	
	/*rep(m,1,8000)
	{
		fprintf(stderr,"%d\n",m);
		rep(c,0,4)
		{
			bool ok = check(m,c);
			if (!ok)
			{
				fprintf(stderr,"ERROR %d %d\n",m,c);
				check(m,c);
			}
		}
	}
	return;*/
	int m;
	cin>>m;
	rep(i,0,10)
		Cnt[i] = calcCnt(m,i);
	if (Cnt[0]>0)
		--Cnt[0];
	res=0;
	rep(s,1,10)
	{
		ll curr = Cnt[s];
		rec(0,s,0,curr);
	}
	cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("barns.in","r",stdin);
	//freopen("barns.out","w",stdout);
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