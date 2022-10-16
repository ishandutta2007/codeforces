#include<bits/stdc++.h>
#define int long long
using namespace std;
const double pi=acos(-1);
bool s[2001][2001];
int a,b,c,d,n,m;
#define calc(x,y,a,b) (x>a||(x==a&&y>b))
void dfs(int x,int y)
{
    s[x][y]=0;
    m++;
    if(calc(x,y,a,b))a=x,b=y;
    if(calc(c,d,x,y))c=x,d=y;
    if(x+1<n&&s[x+1][y])dfs(x+1,y);
    if(y+1<n&&s[x][y+1])dfs(x,y+1);
    if(x&&s[x-1][y])dfs(x-1,y);
    if(y&&s[x][y-1])dfs(x,y-1);
}
main()
{
	cin>>n;
    for(int x=0;x<n;x++)
    for(int y=0;y<n;y++)
    cin>>s[x][y];
    int an1=0,an2=0;
    for(int x=0;x<n;x++)
    for(int y=0;y<n;y++)
    if(s[x][y])
    {
        m=0;
        a=d=-1;
        b=c=20000;
        dfs(x,y);
        if(m<150)continue;
        if(m>((a-c)*(a-c)+(b-d)*(b-d))*0.55)an1++;
        else an2++;
    }
    cout<<an1<<' '<<an2<<endl;
}