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

#define dec __dec

typedef long long i64;

bool prime(int n)
{
    for (int i=2;(i64)i*i<=(i64)n;++i)
        if(n%i==0)
            return false;
    return true;
}

const int N=1000*100+1;
vector<int> pr;
int sum[N*100];
int dec[N*100];

void init()
{
    for (int i=0;i<N*100;++i)
        sum[i]=dec[i]=0;
    for(int i=2;i<N/10;++i)
        if(prime(i))
            pr.push_back(i);
}

vector<int> pw[2*N], d[2*N];

void fact(i64 val, int id)
{
    i64 cur=val;
    for (int i=0; (i64)pr[i]*pr[i]<=(i64)val&&i<pr.size();++i)
        if(val%pr[i]==0)
        {
            d[id].push_back(pr[i]);
            pw[id].push_back(0);
            while(cur%pr[i]==0)
                ++pw[id].back(), cur /= pr[i];
        }
    
    if(cur>1)
        pw[id].push_back(1), d[id].push_back(cur);
}

int a[N], b[N];   

int getpw(int a, int n)
{
    int res=1;
    for (int i=0;i<n;++i)
        res*=a;
    return res;
}     

int main()
{
    
    init();
    
    int n, m;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;++i)
        scanf("%d", &a[i]);
    for(int i=0;i<m;++i)
        scanf("%d",&b[i]);
    
    for(int i=0;i<n;++i)
        fact(a[i],i);
    for(int i=0;i<m;++i)
        fact(b[i],i+N);
    
    for(int i=N;i<m+N;++i)
        for(int j=0;j<d[i].size();++j)
            sum[d[i][j]]+=pw[i][j];
    
    for(int i=0;i<n;++i)
        for(int j=0;j<d[i].size();++j)
            dec[d[i][j]]+=min(pw[i][j],sum[d[i][j]]-dec[d[i][j]]);
    
    printf("%d %d\n",n,m);
    
    for(int i=0;i<N*100;++i)
        sum[i]=dec[i];
    
    for(int i=0;i<n;++i)
    {
        int cur=1;
        for(int j=0;j<d[i].size();++j)
        {
            int p=pw[i][j];
            pw[i][j]-=min(p,dec[d[i][j]]);
            dec[d[i][j]]-=min(p,dec[d[i][j]]);
            cur*=getpw(d[i][j],pw[i][j]);
        }
        printf("%d ", cur);
    }
    printf("\n");
    
    for(int i=N;i<m+N;++i)
    {
        int cur=1;
        for(int j=0;j<d[i].size();++j)
        {
            int p=pw[i][j];
            pw[i][j]-=min(p,sum[d[i][j]]);
            sum[d[i][j]]-=min(p,sum[d[i][j]]);
            cur*=getpw(d[i][j],pw[i][j]);
        }
        printf("%d ", cur);
    }
    
    return 0;
}