#include <bits/stdc++.h>
using namespace std;

int k, n, s, p;


int main()
    {
    cin >> k >> n >> s >> p;

    int minpaper = (s+n-1)/s;
    //cout << minpaper << endl;
    minpaper*= k;

//cout << minpaper << endl;

    cout << (minpaper+p-1)/p;
    return 0;
}