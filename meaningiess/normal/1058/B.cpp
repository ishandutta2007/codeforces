#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,d,m,x,y;
int main()
{
    cin>>n>>d>>m;
    while (m--)
    {
    	cin>>x>>y;
    	if (x+y>=d && x+y<=2*n-d && y<=x+d && y>=x-d) puts("YES");
    	else puts("NO");
	}
}