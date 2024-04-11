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

int main()
{
    ios_base::sync_with_stdio(0);
    
    int k,b,n;
    cin>>k>>b>>n;
    
    i64 s=0,res=0,bad=0,cur=0;
    map<int, int> dp;
    dp.insert(MP(0,1));
    
    for(int i=0;i<n;++i)
    {
        int a;
        cin>>a;
        
        if(a==0)
            ++cur;
        else
        {
            bad+=cur*(cur+1)/2;
            cur=0;
        }
        
        s+=a;
        s%=(k-1);
        
        int want=(s-b+k-1)%(k-1);
        
        res+=(dp.count(want)?dp[want]:0);
        if(dp.count(s))
            dp[s]++;
        else
            dp.insert(MP(s,1));
    }
    bad+=cur*(cur+1)/2;
    if(b==k-1)
        res-=bad;
    if(b==0)
        res=bad;
            
    cout<<res;
  
    return 0;
}