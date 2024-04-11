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
	char str[1001];
	int k;
	scanf("%d %s",&k,str);
	int cnt[300]={0};
	int n=strlen(str);
	rep(i,0,n)
		cnt[str[i]]++;
	if (n%k!=0)
	{
		puts("-1");
		return 0;
	}
	int need=n/k;
	char res[1001]={0};
	int t=0;
	rep(i,0,300)
		if (cnt[i])
		{
			if (cnt[i]%k==0)
			{
				rep(j,0,cnt[i]/k)
					res[t++]=i;
			}
			else
			{
				puts("-1");
				return 0;
			}
		}
	rep(i,0,k)
		printf("%s",res);
	putchar('\n');
	return 0;
}