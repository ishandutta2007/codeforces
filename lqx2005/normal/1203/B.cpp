#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include<climits>
typedef long long ll;
using namespace std;
const int N=10000;
int n,q;
int bucket[N+5],x;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		memset(bucket,0,sizeof(bucket));
		scanf("%d",&n);
		for(int i=1;i<=4*n;i++) scanf("%d",&x),bucket[x]++;
		bool flag=0;
		for(int i=1;i<=N;i++) if(bucket[i]%2==1) flag=1;
		if(flag)
		{
			printf("No\n");
			continue;
		}
		int area;
		int minlen,maxlen;
		for(int i=1;i<=N;i++)
		{
			if(bucket[i]>0)
			{
				minlen=i;
				break;
			}
		} 
		for(int i=N;i>=1;i--)
		{
			if(bucket[i]>0)
			{
				maxlen=i;
				break;
			}
		}
		area=minlen*maxlen;
		vector<int> v;
		for(int i=1;i<=N;i++) 
		{
			if(bucket[i]>0)
			{
				if(area%i!=0)
				{
					flag=1;
					break;
				}
				else
				{
					if(bucket[i]==bucket[area/i])
					{
						bucket[i]=0;
						bucket[area/i]=0;
					}
					else 
					{
						flag=1;
						break;
					}
				}
			}
		}
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		
	}
	return 0;
}