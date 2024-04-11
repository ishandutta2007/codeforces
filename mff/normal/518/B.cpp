#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;
int B[500];
bool A[220000];

int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.length(); i++)
        B[(int)b[i]]++;
    int Y = 0;
    int W = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (B[(int)a[i]] > 0)
        {
            Y++;
            B[(int)a[i]]--;
            A[i] = true;
        }
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (!A[i] && B[(int)a[i]-32] > 0)
        {
            W++;
            B[(int)a[i]-32]--;
        }
        else if (!A[i] && B[(int)a[i]+32] > 0)
        {
            W++;
            B[(int)a[i]+32]--;
        }
    }
    cout << Y << " " << W << endl;
    return 0;
}