#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long
#define sqr(a) (a) * (a)
#define S second
#define F first
#define m_p make_pair
#define p_b push_back

int win(char a, char b) {
    if(a == b) return 0;
    if(a == 'S' && b == 'P') return 1;
    if(a == 'P' && b == 'R') return 1;
    if(a == 'R' && b == 'S') return 1;
    return -1;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n;
    string a, b;
    cin >> a >> b;
    m = a.length();
    k = b.length();
    int lcm = m * k / gcd(m, k);
    int n1 = 0, n2 = 0;
    for(int i = 0; i < lcm; ++i) {
            int cur = win(a[i % m], b[i % k]);
            if(cur == 1)
                   ++n2;
            if(cur == -1)
                   ++n1;
    }
    n1 *= n / lcm;
    n2 *= n / lcm;
    for(int i = 0; i < n % lcm; ++i) {
            int cur = win(a[i % m], b[i % k]);
            if(cur == 1)
                   ++n2;
            if(cur == -1)
                   ++n1;
    }
    
    cout << n1 << " " << n2;
    
    cin >> n;
                   
    return 0;
}