#include <iostream>
#include <cstdio>
#include <queue>
 
int a[1010000];
std::priority_queue<int> pq;
 
int main()
{
	int n; scanf("%d", &n);
	int id;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == -1) id = i; 
	}
	
	int w = 1;
	for(int i = 1; i <= n; i++)
	{
		if(i == w)
		{
			if(i > id) pq.push(a[i]);
			w *= 2;
		}
		else
		{
			if(i > id)
			{
				if(!pq.empty() && a[i] < pq.top())
				{
					pq.pop();
					pq.push(a[i]); 
				}
			}
		}
	}
	
	long long ans = 0;
	while(!pq.empty()) {ans += pq.top(); pq.pop();}
	printf("%lld\n", ans);
}