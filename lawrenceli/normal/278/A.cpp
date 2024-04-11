#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum;
vector<int> d;
int s, t;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int a; cin >> a; d.push_back(a); sum+=a;
    }
    cin >> s >> t;
    if (s>t) swap(s, t);
    int num=0;
    for (int i=s-1; i<t-1; i++) num+=d[i];
    cout << min(num, sum-num) << endl;
}