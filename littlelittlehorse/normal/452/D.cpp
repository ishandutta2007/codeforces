#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, t1, t2, t3, n1, n2, n3, ans;
map<int, int> a1, a2, a3;

int calc(map<int, int> &a){
     return a.begin()->first;
}

inline void work(map<int, int> &a, int value, int x){
     map<int, int>::iterator itr = a.upper_bound(value);
     --itr;
     a[value + x]++;
     if (!--(itr->second)) a.erase(itr);
}

int main(){
     //freopen("d.in", "r", stdin);
     //freopen("d.out", "w", stdout);
     scanf("%d%d%d%d%d%d%d", &n, &n1, &n2, &n3, &t1, &t2, &t3);
     a1.clear(); a1[0] = n1;
     a2.clear(); a2[0] = n2;
     a3.clear(); a3[0] = n3;
     int ans = 0;
     for (int i = 1; i <= n; i++)
     {
          int  value1 = calc(a1), value2 = calc(a2), value3 = calc(a3),
               value = max(value1, value2 - t1);
               value = max(value, value3 - t1 - t2);
          work(a1, value, t1); work(a2, value + t1, t2); work(a3, value + t1 + t2, t3);
          ans = value + t1 + t2 + t3;
     }
     printf("%d\n", ans);
}