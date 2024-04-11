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
 
            
 
int main()
{
    ios_base::sync_with_stdio(0);
    
    set<int> s;
    for (int i = 0; i < 4; ++i)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    
    cout << 4 - s.size();

    
    return 0;
}