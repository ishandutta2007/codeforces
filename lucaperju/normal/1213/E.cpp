#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,k=0,s=0,cnt=0,m;
    cin>>n;
    char x,y,z,a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1!=b1 && a2!=b2)
    {
        for(x='a'; x<='c'; ++x)
            for(y='a'; y<='c'; ++y)
                for(z='a'; z<='c'; ++z)
                {
                    if(x==y || y==z || x==z)
                        continue;
                    if(x==a1 && y==b1 || y==a1 && z==b1)
                        continue;
                    if(x==a2 && y==b2 || y==a2 && z==b2)
                        continue;
                    ++cnt;
                    break;
                }
        if(!cnt)
            cout<<"NO";
        else
        {
            cout<<"YES\n";
            for(x='a'; x<='c'; ++x)
                for(y='a'; y<='c'; ++y)
                    for(z='a'; z<='c'; ++z)
                    {
                        if(x==y || y==z || x==z)
                            continue;
                        if(x==a1 && y==b1 || y==a1 && z==b1)
                            continue;
                        if(x==a2 && y==b2 || y==a2 && z==b2)
                            continue;
                        for(i=1; i<=n; ++i)
                            cout<<x;
                        for(i=1; i<=n; ++i)
                            cout<<y;
                        for(i=1; i<=n; ++i)
                            cout<<z;
                        return 0;
                    }
        }
    }
    else
    {
        for(x='a'; x<='c'; ++x)
            for(y='a'; y<='c'; ++y)
                for(z='a'; z<='c'; ++z)
                {
                    if(x==y || y==z || x==z)
                        continue;
                    if(x==a1 && y==b1 || y==a1 && z==b1 || z==a1 && x==b1)
                        continue;
                    if(x==a2 && y==b2 || y==a2 && z==b2 || z==a2 && x==b2)
                        continue;
                    ++cnt;
                    break;
                }
        if(!cnt)
            cout<<"NO";
        else
        {
            cout<<"YES\n";
            for(x='a'; x<='c'; ++x)
                for(y='a'; y<='c'; ++y)
                    for(z='a'; z<='c'; ++z)
                    {
                        if(x==y || y==z || x==z)
                            continue;
                        if(x==a1 && y==b1 || y==a1 && z==b1 || z==a1 && x==b1)
                            continue;
                        if(x==a2 && y==b2 || y==a2 && z==b2 || z==a2 && x==b2)
                            continue;
                        for(i=1; i<=n; ++i)
                            cout<<x<<y<<z;
                        return 0;
                    }
        }
        return 0;
    }
    return 0;
}