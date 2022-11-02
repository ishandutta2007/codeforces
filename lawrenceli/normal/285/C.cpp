#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 300005;

int n;
int a[MAXN];
long long num;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i=0; i<n; i++) num+=abs(a[i]-(i+1));
    cout << num << endl;
}