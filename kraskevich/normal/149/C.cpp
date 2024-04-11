#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

struct boy {
       long long val, pos;
};

bool cmp(boy a, boy b) {
     return a.val < b.val;
}

int main() {
    int n;
    
    cin >> n;
    
    boy a[n];
    
    for(int i = 0; i < n; ++i) {
            cin >> a[i].val;
            a[i].pos = i;
    }
    
    sort(a, a + n, cmp);
    
    vector<long long> f, s;
    long long sum1 = 0, sum2 = 0;
    
    int l = 0, r = n - 1, num = 0;
    while(l < r) {
            int ll = l, rr = r;
            if(sum1 > sum2) 
                   swap(ll, rr);
            f.push_back(a[rr].pos + 1);
            s.push_back(a[ll].pos + 1);
            sum1 += a[rr].val;
            sum2 += a[ll].val;
            ++l;
            --r;
    }
    if(l == r)
         if(sum1 < sum2)
                 f.push_back(a[l].pos + 1);
         else
             s.push_back(a[l].pos + 1);
    
    cout << f.size() << endl;
    for(int i = 0; i < f.size(); ++i)
            cout << f[i] << " ";
    cout << endl;
    cout << s.size() << endl;
    for(int i = 0; i < s.size(); ++i)
            cout << s[i] << " ";
    
    cin >> n;
    
    return 0;
}