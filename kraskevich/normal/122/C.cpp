#include <iostream>
#include <vector>
using namespace std;

vector<long long> luckies;
long long x;

void gen(int k, int pos, long long cur) {
     if(k == pos) {
          x = cur;
          if(cur <= 1e10)
                 luckies.push_back(cur);
     }
     else {
         gen(k, pos + 1, cur * 10 + 4);
         gen(k, pos + 1, cur * 10 + 7);
     }
}

void Init() {
     for(int i = 1;; ++i) {
             gen(i, 0, 0);
             if(x > 1e10)
                  break;
     }
}

long long next(long long n) {
     long long l = 0, r = luckies.size();
     while(l < r - 1) {
             int m = (l + r) / 2;
             if(luckies[m] < n)
                           l = m + 1;
             else
                 r = m;
     }
     return (luckies[l] >= n ? luckies[l] : luckies[r]);
} 

int main() {
    Init();
    
    long long l, r, res = 0;
    
    cin >> l >> r;
    
    long long i = l;
    
    while(i <= r) {
            long long t = next(i);
            res += t * (min(t, r) - i + 1);
            i = t + 1;
    }
    
    cout << res << endl;
    cin >> l;
    
    return 0;
}