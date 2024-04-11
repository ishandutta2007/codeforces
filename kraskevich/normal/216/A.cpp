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
    
    int a,b,c;
    cin>>a>>b>>c;
    
    cout<<b*c+a*c+a*b-a-b-c+1;
    
    return 0;
}