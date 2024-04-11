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

int A[110];

int main()
{
    int n;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i != 0 && max < A[i] - A[i-1])
            max = A[i] - A[i-1];
    }
    int min = 1000;
    for (int i = 1; i < n - 1; i++)
    {
        if (min > A[i+1] - A[i-1])
            min = A[i+1] - A[i-1];
    }
    if (max < min)
        swap(max,min);
    cout << max << endl;
    return 0;
}