#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 400500;

int n, k;
int l, r;
long long num;
int a[MAXN];
map<int, int> b;

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    while (l<n) {
        bool suc = true;
        while (b[a[r-1]]<k) {
            if (r>n) {
                suc = false;
                break;
            }
            r++;
            b[a[r-1]]++;
        }
        if (!suc) break;
        num+=n-r+1;
        l++;
        b[a[l-1]]--;
    }
    cout << num << endl;
}