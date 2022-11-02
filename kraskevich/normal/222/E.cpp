#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>


typedef long long i64;


const i64 mod=1000*1000*1000+7;


struct matr
{
    i64 a[52][52];
    
    matr()
    {
        for(int i=0;i<52;++i)
            for(int j=0;j<52;++j)
                a[i][j]=0;
    }
    
    matr operator * (matr b)
    {
        matr c=matr();
        for(int i=0;i<52;++i)
            for(int j=0;j<52;++j)
                for(int k=0;k<52;++k)
                    c.a[i][j] += a[i][k]*b.a[k][j], c.a[i][j]%=mod;
        return c;
    }
};

matr pw(matr a, i64 n)
{
    matr res=matr();
    for(int i=0;i<52;++i)
        res.a[i][i]=1;
    
    while(n)
    {
        if(n%2)
            res=res*a;
        a=a*a;
        n/=2ll;
    }
    
    return res;
}

int num(char c)
{
    if (c >= 'a' && c <= 'z')
        return (int)c-(int)'a';
    else
        return (int)c-(int)'A'+26;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    i64 n,m,k;
    cin>>n>>m>>k;
    
    matr t=matr();
    
    bool ok[52][52];
    for(int i=0;i<52;++i)
        for(int j=0;j<52;++j)
            ok[i][j]=0;
    for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
            ok[i][j]=1;
    
    for(int i=0;i<k;++i)
    {
        string s;
        cin>>s;
        ok[num(s[0])][num(s[1])]=0;
    }
    
    for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
            if(ok[j][i])
                t.a[i][j]=1;
    
    t=pw(t,n-1);
    
    i64 res=0;
    for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
            res+=t.a[i][j], res%=mod;
    
    cout<<res;
    
    cin>>n;
    
    return 0;
}