#include <bits/stdc++.h>
using namespace std;

long delete1 (long num, long k)
    {
    //cout << num << " " << k << endl;
    if (num%10 < k) return delete1(num/10, k - num%10 -1);
    else return num - k;
    }

int n, k;

int main()
    {
    cin >> n >> k;

    cout << delete1(n, k);

    return 0;

    }