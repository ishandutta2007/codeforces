#include<bits/stdc++.h>
int T,x,y;
using namespace std;
signed main()
{
    scanf("%d",&T);
    while (T--)
    {
    	scanf("%d%d",&x,&y);
    	if (x<y) cout<<y-x<<endl; else
    	cout<<(x+y)%2<<endl;
    }
}