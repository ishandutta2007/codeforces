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




const int N=400*1000;
vector<int> p(N,0);
vector<int> sf(N,0);
int cnt[N][26];

int getCnt(int l, int r, char c)
{
    //cout<<l<< " "<<r << " "<<char(c+'a') <<endl;
    if(r<0)
        return 0;
    if(r<l)
        return 0;
    l=max(l,0);
    int res=cnt[r][c];
    if(l)
        res-=cnt[l-1][c];
    //cout<<res<<endl;
    return res;
    
}


int main()
{
    for (int i=0;i<N;++i)
        for (int j=0;j<26;++j)
            cnt[i][j]=0;
            
    ios_base::sync_with_stdio(0);
    
    string a, b;
    cin >> a >> b;
    
    int n=a.length();
    int m=b.length();
    
    int lst=0;
    for (int i=0;i<n;++i)
    {
        if(lst!=m&&a[i]==b[lst])
            lst++;
        p[i]=lst;
    }
    
    lst=0;
    for(int i=n-1;i>=0;--i)
    {
        if(lst!=m&&a[i]==b[m-lst-1])
            ++lst;
        sf[i]=lst;
    }
    
    for(int i=0;i<m;++i)
        for(int j=0;j<26;++j)
        {
            cnt[i][j]=(((int)b[i]==(j+(int)'a'))?1:0);
            if(i)
                cnt[i][j]+=cnt[i-1][j];
        }
    
    bool ok=true;
    
   /* for(int i=0;i<n;++i)
        cout<<p[i]<< " "<<sf[i]<<endl;
    cout<<endl;*/
    
    for(int i=0;i<n;++i)
    {
        int pref=p[i];
        int suf;
        
        if(i==n-1)
            suf=0;
        else
            suf=sf[i+1];
        
        if(!getCnt(m-suf-1,pref-1,a[i]-'a'))
            ok=false;
    }
    
    cout<<(ok?"Yes":"No");
    
    //cin>>a;
    
    
    return 0;
}