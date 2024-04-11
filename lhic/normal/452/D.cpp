#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>

typedef long long ll;
typedef long double ld;

const int MAX_N = 110000;

using namespace std;

int w1;
int w2;
int w3;
queue<int> z1;
queue<int> z2;
queue<int> z3;

int k, n1, n2, n3, t1, t2, t3;
int en;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    w1 = k;
    en = 0;
    int i = 0;
    while (en < k)
    {
        while (!z3.empty() && z3.front() <= i)
        {
            z3.pop();
            ++en;
        }
        while (!z2.empty() && z2.front() <= i)
        {
            z2.pop();
            ++w3;
        }
        while (!z1.empty() && z1.front() <= i)
        {
            z1.pop();
            ++w2;
        }
        while (w1 && z1.size() < n1)
        {
            --w1;
            z1.push(i + t1);
        }
        while (w2 && z2.size() < n2)
        {
            --w2;
            z2.push(i + t2);
        }
        while (w3 && z3.size() < n3)
        {
            --w3;
            z3.push(i + t3);
        }
        ++i;
    }
    cout << i - 1;


    return 0;
}