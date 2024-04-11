#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, b;
int a[Maxn];
int best;

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++) cin >> a[i];
    best = b;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int dol = b / a[i];
            best = max(best, b % a[i] + dol * a[j]);
        }
    cout << best << endl; 
    return 0;
}