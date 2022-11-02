#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int t;
bool pos[180];

void precompute() {
    for (int i=3; i<=1000; i++) {
        int x = 180*(i-2);
        if (x%i==0) pos[x/i]=true;
    }
}

int main() {
    //freopen("270A.in", "r", stdin);
    precompute();
    cin >> t;
    for (int i=0; i<t; i++) {
        int x;
        cin >> x;
        if (pos[x]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}