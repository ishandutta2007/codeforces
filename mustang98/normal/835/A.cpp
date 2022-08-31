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
#include <ctime>
#include <unistd.h>

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
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int l1 = 2 * t1 + v1 * s;
    int l2 = 2 * t2 + v2 * s;
    if (l1 < l2) {
        cout << "First";
    } else if (l1 > l2) {

        cout << "Second";
    } else {
        cout << "Friendship";
    }
    return 0;
}