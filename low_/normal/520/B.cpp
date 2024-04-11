#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

int m, n;
int shortest[20005];
queue <int> Q1, Q2;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<20005; i++) shortest[i]=-1;
	cin>>n>>m;
	
	Q1.push(n);
	Q2.push(0);
	
	while (!Q1.empty())
	{
		int num=Q1.front();
		Q1.pop();
		int cnt=Q2.front();
		Q2.pop();
		
		if (num==m) 
		{
			cout<<cnt;
			return 0;
		}
		
		if (num-1>0 && shortest[num-1]==-1)
		{
			shortest[num-1]=cnt+1;
			Q1.push(num-1);
			Q2.push(cnt+1);
		}
		if (num*2<20005 && shortest[num*2]==-1)
		{
			shortest[num*2]=cnt+1;
			Q1.push(num*2);
			Q2.push(cnt+1);
		}
	}
	
}