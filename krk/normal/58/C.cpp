#include <cstdio>
#include <iostream>
using namespace std;

const int Maxn = 100001;

int n, h, dntchange[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        if (i < n/2 && h-i > 0) dntchange[h-i]++;
        else if (i >= n/2 && h-(n-1-i) > 0) dntchange[h-(n-1-i)]++; 
    }
    int mx = -1;
    for (int i = 1; i < Maxn; i++)
       if (mx == -1 || dntchange[i] > mx) mx = dntchange[i];
    cout << n-mx << endl;
    return 0;
}