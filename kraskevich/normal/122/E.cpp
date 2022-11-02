#include <iostream>
#include <vector>
using namespace std;

vector<long long> luckies;
long long x;

void gen_luck(int k, int pos, long long cur) {
     if(k == pos) {
          x = cur;
          if(cur <= 1e10)
                 luckies.push_back(cur);
     }
     else {
         gen_luck(k, pos + 1, cur * 10 + 4);
         gen_luck(k, pos + 1, cur * 10 + 7);
     }
}

void Init() {
     for(int i = 1;; ++i) {
             gen_luck(i, 0, 0);
             if(x > 1e10)
                  break;
     }
}


vector<int> perm;
vector<bool> u;

long long fact(long long n) {
     long long res = 1;
     for(long long i = 2; i <= n; ++i)
              res *= i;
     return res;
}

void gen(long long l, long long pos, long long num) {
     if(pos == l)
            return;
     long long sz = l - pos;
     int cur = 1;
     while((cur- 1) * fact(sz - 1) < num)
                    ++cur;
     --cur;
     int cnt = 0, j = 0;
     while(cnt < cur) {
               if(!u[j]) 
                         ++cnt;
               ++j;
     }
     --j;
     
     u[j] = true;
     perm[pos] = j;
     
     gen(l, pos + 1, num - (cur - 1) * fact(sz - 1));
}

bool lucky(long long n) {
     while(n) {
              if(n % 10 != 4 && n % 10 != 7)
                   return false;
              n /= 10;
     }
     return true;
} 

int low(long long n) {
    int l = 0, r = luckies.size();
    while(l < r - 1) {
            int m = (l + r) / 2;
            if(luckies[m] < n)
                         l = m;
            else
                r = m;
    }
    if(n < 4)
         return 0;
    else
        return (luckies[r] <= n ? r + 1 : l + 1);
}   

int main() {
    Init();
    long long n, k;
    
    cin >> n >> k;
    
    if(n <= 13 && fact(n) < k) {
         cout << -1;
         return 0;
    }
    
    int len = 1;
    
    while(fact(len) < k && len < 13)
                    ++len;
    
    u.assign(len, false);
    perm.resize(len);
    
    gen(len, 0, k);
    
    vector<long long> res(len);
    long long start = n - len + 1;
    long long ans = low(n - len);
    
    for(int i = 0; i < len; ++i)
            res[i] = perm[i] + start;
    
    
    
    for(int i = 0; i < len; ++i) {
            if(lucky(n - len + i + 1) && lucky(res[i]))
                       ++ans;
    }
    
    cout << ans << endl;
    
    cin >> n;
    
    return 0;
}