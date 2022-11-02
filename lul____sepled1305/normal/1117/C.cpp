#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,n,i;
long long ans;
string s;
pair<int,int> quick[100000+10];

bool check(long long k)
{
    long long dis=0,disx=0,disy=0;
    disx = (k/n)*quick[n].first + quick[k%n].first;
    disy = (k/n)*quick[n].second + quick[k%n].second;
    disx = x - disx;
    disy = y - disy;
    dis  = abs(disx)+abs(disy);
    if(dis <= k)
        return true;
    else
        return false;
}

long long b_search(long long mini,long long maxi)
{
    if(!check(maxi))
        return -1;
    while(mini<maxi)
    {
        long long mid = (mini+maxi)/2;
        if(mini == mid)
        {
            if(!check(mini))
                mini = maxi;
            else
                maxi = mini;
            break;
        }
        if(check(mid))
            maxi = mid;
        else
            mini = mid+1;
    }
    return mini;
}

int main()
{
    cin>>a>>b>>x>>y;
    x-=a; y-=b;
    cin>>n;
    cin>>s;
    quick[0] = {0,0};
    for(i=1;i<=n;i++)
    {
        pair<int,int> bef = quick[i-1];
        if(s.at(i-1)=='U')
            quick[i] = {quick[i-1].first,quick[i-1].second+1};
        if(s.at(i-1)=='D')
            quick[i] = {quick[i-1].first,quick[i-1].second-1};
        if(s.at(i-1)=='L')
            quick[i] = {quick[i-1].first-1,quick[i-1].second};
        if(s.at(i-1)=='R')
            quick[i] = {quick[i-1].first+1,quick[i-1].second};
    }
    cout<<b_search(1,1e15);
}