#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 - 1;
    } else {
        cout << n / 2;
    }
    return 0;
}