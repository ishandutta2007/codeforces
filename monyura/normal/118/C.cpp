#pragma comment(linker,"/STACK:32000000")
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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct elem
{
	int val;
	int men;
	char c;
};

bool operator<(const elem &a,const elem& b)
{
	if (a.val!=b.val) return a.val<b.val;
	return a.men<b.men;
}

int main()
{
	int n,k;
	cin>>n>>k;
	char str[10001];
	elem B[10001];
	scanf(" %s",str);
	int best=1e9;
	char curr[10001];
	int Cnt[300][2]={0};
	string res;
	rep(c,'0','9'+1)
	{
		rep(i,'0','9'+1)
			Cnt[i][0]=Cnt[i][1]=0;
		int cnt=0;
		rep(i,0,n)
		{
			B[i].val=abs(str[i]-c);
			B[i].men=str[i]<c;
			B[i].c=str[i];
		}
		sort(B,B+n);
		int tot=0;
		rep(j,0,k)
		{
			tot+=B[j].val;
			Cnt[B[j].c][B[j].men]++;
		}
		rep(i,0,n)
		{
			curr[i]=str[i];
			if (Cnt[curr[i]][0]>0)
			{
				Cnt[curr[i]][0]--;
				curr[i]=c;
			}
		}
		for (int i=n-1;i>=0;i--)
		{
			if (Cnt[curr[i]][1]>0)
			{
				Cnt[curr[i]][1]--;
				curr[i]=c;
			}
		}
		curr[n]=0;
		if (tot<best)
		{
			best=tot;
			res=curr;
		}
		if (tot==best && string(curr)<res)
			res=curr;

	}
	cout<<best<<endl;
	printf("%s\n",res.c_str());
	return 0;
}
/*

*/