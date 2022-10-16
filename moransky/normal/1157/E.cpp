#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef multiset<int>::iterator MLT;
const int N = 200010;
int n, a[N], b[N], nxt[N], pre[N];
bool st[N];
// >= n - a[i] 
multiset<int> s;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", b + i), s.insert(b[i]);
    
    for(int i = 1; i <= n; i++){
        MLT x = s.lower_bound(n - a[i]);
        if(x == s.end()) x = s.begin();
        printf("%d ", (a[i] + *x) % n);
        s.erase(x);

    }
    return 0;
}