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
int Fact[11];
int A[10000];

int main()
{
    Fact[0] = 1;
    for (int i = 1; i < 10; i++)
        Fact[i] = Fact[i-1]*i;
    int n, count = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int a = (int)(s[i] - '0');
        if (a == 2)
            A[count++] = 2;
        else if (a == 3)
            A[count++] = 3;
        else if (a == 4)
        {
            A[count++] = 3;
            A[count++] = 2;
            A[count++] = 2;
        }
        else if (a == 5)
            A[count++] = 5;
        else if (a == 6)
        {
            A[count++] = 5;
            A[count++] = 3;
        }
        else if (a == 7)
            A[count++] = 7;
        else if (a == 8)
        {
            A[count++] = 7;
            A[count++] = 2;
            A[count++] = 2;
            A[count++] = 2;
        }
        else if (a == 9)
        {
            A[count++] = 7;
            A[count++] = 3;
            A[count++] = 3;
            A[count++] = 2;
        }
    }
    sort(A,A+count);
    for (int i = count - 1; i >= 0 ; i--)
    {
        cout << A[i];
    }
    cout << endl;
    return 0;
}