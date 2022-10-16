#include <iostream>
#include <cstring>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;
char c[1305];
bool v[5201][5201];
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    long long n,k,i,j,s=0,m,cnt=0,cur,t,cj,vlc,mn=99999999;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>c;
        for(j=0; j<n/4; ++j)
        {
            if(c[j]>='A' && c[j]<='Z')
                vlc=c[j]-'A'+10;
            else
                vlc=c[j]-'0';
            v[i][j*4+4]=vlc%2;
            vlc/=2;
            v[i][j*4+3]=vlc%2;
            vlc/=2;
            v[i][j*4+2]=vlc%2;
            vlc/=2;
            v[i][j*4+1]=vlc%2;
            vlc/=2;
        }
    }
    for(i=1; i<=n; ++i)
    {
        cur=-1;
        for(j=1; j<=n; ++j)
        {
            if(j==1 || v[i][j]!=v[i][j-1])
            {
                if(j==1)
                {
                    cnt=1;
                    continue;
                }
                if(cur==-1)
                    cur=cnt;
                else
                    cur=cmmdc(cur,cnt);
                cnt=1;
            }
            else
                ++cnt;
        }
        if(cur==-1)
            cur=cnt;
        else
            cur=cmmdc(cur,cnt);
        mn=min(mn,cur);
    }
    for(j=1; j<=n; ++j)
    {
        cur=-1;
        for(i=1; i<=n; ++i)
        {
            if(i==1 || v[i][j]!=v[i-1][j])
            {
                if(i==1)
                {
                    cnt=1;
                    continue;
                }
                if(cur==-1)
                    cur=cnt;
                else
                    cur=cmmdc(cur,cnt);
                cnt=1;
            }
            else
                ++cnt;
        }
        if(cur==-1)
            cur=cnt;
        else
            cur=cmmdc(cur,cnt);
        mn=min(mn,cur);
    }
    cout<<mn;
    return 0;
}