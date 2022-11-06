#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100100;
const int inf = 2e9;

//pair < int, int > i[maxn];
int a[100000], p[100000], pmin[100000], sum;

int main()
{
    int n;
    cin >> n;
    for ( int i = 0;i < n; i++ )
        pmin[i] = 200;
    for ( int i = 0; i < n; i++ )
    {
        cin>>a[i]>>p[i];
        sum+=a[i];
        if (i==0)
        pmin[i]=p[i];
        else
        {
            pmin[i]=min(p[i],pmin[i-1]);
        }

    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans+=a[i]*pmin[i];
    }
    cout << ans;
    return 0;
}