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

int main()
{
    int n,k;
    cin >> n >> k;

    for(int i = 1 ; i <= k ; i++ )
    {
        cout << 2*i - 1 << ' ' << 2*i << ' ' ;
    }
    for(int i = k + 1 ; i <= n ; i++ )
    {
        cout << 2*i << ' ' << 2*i -1 << ' ';
    }
}