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
const int inf=1000*1000*1000;

const int N=111111;
int a[N],b[N];
int x;
int n;

bool check(int pos)
{
    int l=n-pos-1,r=n-1;
    
    bool ok1=true;
    
    while(l<n)
    {
        if(a[l]+b[r]<x)
            ok1=false;
        ++l;
        --r;
    }
    
    l=n-pos-1,r=n-1;
    
    bool ok2=true;
    
    while(l<n)
    {
        if(a[r]+b[l]<x)
            ok2=false;
        ++l;
        --r;
    }
    return ok2||ok1;
}
        

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>x;
    
    for (int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    
    int l=0;
    int r=n-1;
    
    while(l<r)
    {
        int m=(l+r+1)/2;
        if(check(m))
            l=m;
        else
            r=m-1;
    }
    
    cout<<1<<" "<<l+1<<endl;
    
    return 0;
}