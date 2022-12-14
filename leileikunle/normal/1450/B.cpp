#include <bits/stdc++.h>
using namespace std;
struct point{
	int x;
	int y;
}; 
int main()
{
	int T; cin>>T;
	while(T--)
	{
		point a[101] = {0};
		int n,k; cin>>n>>k;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].x;
			cin>>a[i].y;
		}
		int b = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x1 = abs(a[i].x-a[j].x); 
				int y1 = abs(a[i].y-a[j].y);
				if(x1+y1>k)
				{
					break;
				}
				if(j==n){
					b = 1;
				}
			}
			if(b) break;
		}
		if(b) cout<<1<<endl;
		else cout<<-1<<endl; 
	}
}