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


int a[1000][1000];
int px[1000];
int py[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n,m,k;
    cin>>n>>m>>k;
    
    for (int i=0;i<1000;i++)
        px[i]=py[i]=i;
    
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> a[i][j];
    
    for(int i=0;i<k;++i)
    {
        char c;
        int x, y;
        cin>>c>>x>>y;
        --x;
        --y;
        if (c=='c')
            swap(py[x],py[y]);
        if (c=='r')
            swap(px[x],px[y]);
        if (c=='g')
            cout<<a[px[x]][py[y]] << endl;
        }
    
    cin>>n;
    
    
    return 0;
}