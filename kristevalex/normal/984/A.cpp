#include <bits/stdc++.h>
using namespace std;

int n;

int data[1001];

int compare (const void* x1, const void* x2)
    {
    return (*((int*)x1) - *((int*)x2));
    }

int main()
{
    cin >> n;                                     //

    for (size_t i = 0; i < n; i++)
        {
        cin >> data[i];
        }

    qsort(data, n, sizeof(int), compare);

    cout << data[(n-1)/2];
    return 0;
}