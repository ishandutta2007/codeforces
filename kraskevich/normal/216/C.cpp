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

int n,m,k;
    
int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m>>k;
    
    if(n-1>m)
    {
        cout<<2*k<<endl;
        for(int i=0;i<k;++i)
            cout<<1<<" ";
        for(int i=0;i<k;++i)
            cout<<n<<" ";
    }
    if(n-1==m)
    {
        if(k==1)
            cout<<3<<endl<<1<<" "<<n<<" "<<n+1;
        else
        {
            cout<<2*k<<endl;
            for(int i=0;i<k;++i)
                cout<<1<<" ";
            cout<<n<<" ";
            for(int i=0;i<k-1;++i)
                cout<<n+1<<" ";
        }
    }
    if(n==m)
    {
        if(k==1)
        {
            if(n==2)
                cout<<4<<endl<<1<<" "<<2<<" "<<3<<" "<<4;
            else
                cout<<3<<endl<<1<<" "<<n<<" "<<n+2<<endl;
        }
        else
        {
            cout<<2*k+1<<endl;
            for(int i=0;i<k;++i)
                cout<<1<<" ";
            cout<<n<<" ";
            for(int i=0;i<k-1;++i)
                cout<<n+1<<" ";
            cout<<n+m<<" ";
        }
    }

    
    return 0;
}