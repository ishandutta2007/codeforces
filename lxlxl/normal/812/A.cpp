#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 4;

bool _in[maxn],_out[maxn];
bool man[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	for(int i=1;i<=4;i++)
	{
		int li=(i==1)?4:i-1,ri=(i==4)?1:i+1;
		int ti=(i+2)%4;
		int a1,a2,a3,a4; scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
		if(!ti) ti=4;
		if(a1) _in[li]=_out[i]=true;
		if(a2) _in[ti]=_out[i]=true;
		if(a3) _in[ri]=_out[i]=true;
		if(a4) man[i]=true;
	}
	bool flag=false;
	for(int i=1;i<=4;i++)
	{
		if(man[i])
			if(_in[i]||_out[i])flag=true;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}