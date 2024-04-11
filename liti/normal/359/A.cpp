#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <set>
#include <map>

#define pb push_back
#define SZ(x) (( (int) x.size() ))
#define ll long long
#define pin pair<int,int>
#define vin vector<int>

using namespace std;

const int maxN = 55;

int a[maxN][maxN];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i <  n ;i++)
    {
        for(int j = 0 ; j < m ; j++ )
            cin >> a[i][j];
    }

    bool c1 = false;
    for(int i = 0 ; i <m ; i++ )
    {
         if ( a[0][i] == 1 )
            c1 = true;
        if ( a[n-1][i])
            c1 = true;
    }

    for(int i = 0 ; i < n ;i++ )
    {
        if ( a[i][0] == 1 )
            c1 = true;
        if ( a[i][m-1] )
            c1 =true;
    }

    if (  c1 )
    {

        cout << 2 << endl;
        return 0;
    }

    cout << 4 << endl;
    return 0;
}