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
const double eps = 1e-7;
const int inf = (int)1e9;

#define forn for(int i=0;i<n;++i)
#define REP(i, a, b) for(int i=a;i<=b;++i)

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    
    vector<int> t[n];
    
    for(int i=0;i<n;++i)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;++j)
        {
            int x;
            cin>>x;
            t[i].push_back(x);
        }
    }
    
    for(int i=0;i<n;++i)
        sort(t[i].begin(), t[i].end());
    
    int res=0;
    for(int i=0;i<n;++i)
    {
        vector<int> prev=t[(i-1+n)%n], next=t[(i+1)%n];
        for(int j=1;j<t[i].size();++j)
        {
            int l=0, r=prev.size()-1;
            while(l<r)
            {
                int m=(l+r)/2;
                if(prev[m]<t[i][j-1])
                    l=m+1;
                else
                    r=m;
            }
            
            int ll=l;
            bool ok=true;
            if(prev[ll]<t[i][j-1])
                ok=false;
                
            l=0, r=prev.size()-1;
            while(l<r)
            {
                int m=(l+r+1)/2;
                if(prev[m]>t[i][j])
                    r=m-1;
                else
                    l=m;
            }
            int rr=l;
            if(prev[rr]>t[i][j])
                ok=false;
            int cntl=rr-ll+1;
            if(!ok)
                cntl=0;
            
            l=0, r=next.size()-1;
            while(l<r)
            {
                int m=(l+r)/2;
                if(next[m]<t[i][j-1])
                    l=m+1;
                else
                    r=m;
            }
            
            ll=l;
            ok=true;
            if(next[ll]<t[i][j-1])
                ok=false;
                
            l=0, r=next.size()-1;
            while(l<r)
            {
                int m=(l+r+1)/2;
                if(next[m]>t[i][j])
                    r=m-1;
                else
                    l=m;
            }
            rr=l;
            if(next[rr]>t[i][j])
                ok=false;
            int cntr=rr-ll+1;
            if(!ok)
                cntr=0;
            
            if(cntl!=cntr)
                ++res;
        }
    }
    
    cout << res;
    
    return 0;
}