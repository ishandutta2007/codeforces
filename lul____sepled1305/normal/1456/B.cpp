#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int st, int ed, vector<int> &v)
{
    int cur = 0;
    for(int i=st;i<=ed;i++)
        cur = cur ^ v[i];
    if(cur < v[st-1] || cur > v[ed+1])
        return true;
    return false;
}

bool check(int st, int mid, int ed, vector<int> &v)
{
    int a = 0, b = 0;
    for(int i=st;i<=mid;i++)
        a = a ^ v[i];
    for(int i=mid+1;i<=ed;i++)
        b = b ^ v[i];
    if(a < v[st-1] || b > v[ed+1] || b < a)
        return true;
    return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,mini = 1e9,i,j,k;
    vector<int> v;
    cin>>n;
    if(n>60)
        cout<<1;
    else
    {
        v.push_back(-1);
        for(i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        v.push_back(1e13);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(check(j,i,v) && mini > i-j)
                    mini = i-j;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                for(k=j+1;k<i-1;k++)
                    if(check(j,k,i,v) && mini > i-j-1)
                        mini = i-j-1;
            }
        }
        if(mini == 1e9)
            cout<<-1;
        else
            cout<<mini;
    }
}