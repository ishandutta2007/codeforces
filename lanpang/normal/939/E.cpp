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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL qq , mq , nq , sq;
double ss , mm , nn;
priority_queue < LL,vector<LL>,greater<LL> > q;

int main()
{
	LL i , j , k , x;
	cin >> qq;
	for (i = 1 ; i <= qq ; i++)
	{
		scanf("%I64d",&k);
		if (k == 2)
		{
			mm = mq;
			ss = sq;
			nn = nq;
			ss /= nn;
			mm -= ss;
			printf("%.10lf\n",mm);
		}
		else
		{
			scanf("%I64d",&x);
			if (nq == 0)
			{
				nq = 1;
				sq = x;
				mq = x;
			}
			else
			{
				if (x > mq)
				{
					sq += x-mq;
					q.push(mq);
					mq = x;
				}
				else q.push(x);
				while (!q.empty() && q.top()*nq < sq)
				{
					sq += q.top();
					nq++;
					q.pop();
				}
			}
		}
	}
	return 0;
}