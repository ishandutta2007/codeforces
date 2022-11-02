#include<bits/stdc++.h>
using namespace std;
int T;

int bruteforce(string &s, int height, int l, int r)
{
    int mid = l+r>>1;
    if(l==r)
    {
        if(s.at(l)-'a'!=height)
            return 1;
        else
            return 0;
    }
    else
    {
        int can1=0,can2=0,j;
        for(j=l;j<=mid;j++)
        {
            if(s.at(j)-'a'!=height)
                can1++;
        }
        for(j=mid+1;j<=r;j++)
        {
            if(s.at(j)-'a'!=height)
                can2++;
        }
        int mini = min(can1+bruteforce(s,height+1,mid+1,r),can2+bruteforce(s,height+1,l,mid));
        return mini;
    }
}

void solve()
{
    int n,i,mini = 1e9;
    string s;
    cin>>n>>s;
    mini = bruteforce(s,0,0,n-1);
    cout<<mini<<"\n";
}

int main()
{
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}