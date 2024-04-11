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
const int maxn = 1e5;

int main()
{
    int n, i [maxn], k, kol = 0, z;
    cin >> n;
    for (k = 0; k < n; k++)
        cin >> i[k];
    k = 0;
    while ( k < n ){
        z = 1;
        while (i[k] <= i[k + 1] && k + 1 < n)
            k++, z++;
        k++;
        kol = max ( kol, z );
    }
    cout << kol;
    return 0;
}