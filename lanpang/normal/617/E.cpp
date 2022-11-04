#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x , y , p;
	mmp(){}
	mmp(int xx , int yy){x = xx , y = yy;}
}p[100010];

int n , m , k , sum[100010] , l , r , sn , pos[100010]; 
long long res[1000010] , ans , num[2000010];

bool cmp(mmp x , mmp y)
{
	if (pos[x.x] == pos[y.x])
		return x.y < y.y;
	else
		return pos[x.x] < pos[y.x];
}


int main ()
{
	int i , j , l , r;
	cin >> n >> m >> k;
	sn = sqrt(n);
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&j);
		sum[i] = sum[i-1]^j;
		pos[i] = (i-1)/sn+1;
	}
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].p = i;
	}
	sort(p+1,p+m+1,cmp);
	l = 0;
	r = 0;
	for (i = 1 ; i <= m ; i++)
	{
		while (l < p[i].x-1)
		{
			num[sum[l]]--;
			ans -= num[sum[l]^k];
			l++;
		}
		while (l >= p[i].x)
		{
			l--;
			ans += num[sum[l]^k];
			num[sum[l]]++;
		}
		while(r <= p[i].y)               
        {  
            ans+=num[sum[r]^k];        
            num[sum[r]]++;                  
            r++;  
        }  
        while(r > p[i].y+1)               
        {  
            r--;  
            num[sum[r]]--;                     
            ans-=num[sum[r]^k];        
        }  
		res[p[i].p] = ans;
	}
	for (i = 1 ; i <= m ; i++)
	{
		printf("%I64d\n",res[i]);
	}
	//system("PAUSE");
	return 0;
}