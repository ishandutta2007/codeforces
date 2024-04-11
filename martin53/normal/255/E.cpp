#include<bits/stdc++.h>
using namespace std;
/*
const int lim=1e6+5;
int dp[lim];
int sg(long long x)
{
    vector<int> seen(5,0);
    //cout<<x<<" has ";
    for(long long y=pow(x,1.0/4);y*y<=x;y++)
        if(x<=y*y*y*y&&y*y*y*y<=x*x)
        {
        //cout<<y<<" ";
        seen[dp[y]]=1;
        }
    //cout<<endl;
    int p=0;
    while(seen[p])p++;
    dp[x]=p;
    return p;
}
*/
/*
0-3->0
4-15->1
16-81->2
82-6723->0
6724-50625->3
50626-2562991875->1
*/
long long sg(long long x)
{
    if(x<=3)return 0;
    if(x<=15)return 1;
    if(x<=81)return 2;
    if(x<=6723)return 0;
    if(x<=50625)return 3;
    if(x<=2562991875)return 1;
    return 2;
}
int main()
{
/*
dp[0]=0;
for(int i=50625+1;i<lim;i++)
{
    sg(i);
    if(dp[i]!=1)
    {
        cout<<i<<" "<<dp[i]<<endl;
        system("pause");
    }
    if(i%10000==0)cout<<i<<endl;
}
*/
int x=0;
int n;
long long num;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>num;
    x=x^sg(num);
}
if(x==0)cout<<"Rublo"<<endl;
else cout<<"Furlo"<<endl;
return 0;
}