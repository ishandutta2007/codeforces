#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 5000

typedef long long ll;
typedef pair<int, int> pii;

int n,a[MAX], s[4], p[4];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        s[a[i]]++;
    }

    int k = min(min(s[3],s[2]),s[1]);
    cout << k << endl;
    while (k-- > 0) {
        while(a[p[1]] != 1) p[1]++;
        while(a[p[2]] != 2) p[2]++;
        while(a[p[3]] != 3) p[3]++;

        cout << ++p[1] << " " << ++p[2] << " " << ++p[3] << endl;
    }
    return 0;
}