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


int main()
{
	//freopen("condoms.in", "r", stdin); freopen("condoms.out", "w", stdout);
	ll p,d;
	cin>>p>>d;
	char str[100]={0};
	sprintf(str,"%""lld",p);
	int n=strlen(str);
	ll res=-1;
	rep(i,0,n+1)
	{
		char s[100]={0};
		strcpy(s,str);
		int cnt=0;
		bool was=0;
		int j=n-1;
		for (j=n-1;j>=n-i;j--)
			if (s[j]=='9') cnt++;
			else
			{
				s[j]='9';
				was=1;
				cnt++;
			}
		bool ok=1;
		ll curr=p;
		if (was)
		{
			int otn=1;
			for (int k=j;k>=0;k--)
			{
				if (s[k]-otn<'0')
				{
					otn=1;
					s[k]=s[k]-otn+10;
				}
				else
				{
					s[k]-=otn;
					otn=0;
				}
			}
			if (otn)
				ok=0;
			sscanf(s,"%""lld",&curr);
			if (p-curr>d)
				ok=0;
		}
		if (ok)
			res=curr;
	}
	cout<<res<<endl;

	return 0;
}