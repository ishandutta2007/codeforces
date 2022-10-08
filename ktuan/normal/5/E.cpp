#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int a[2000020];
int R[2000020], RE[2000020];

int F[2000020], E[2000020]; 


int list[2000020];
int nl;

void add(int x) {
    while(nl > 0 && list[nl-1] < x) {
        --nl;
    }
    list[nl++] = x;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;++i) {
        scanf("%d", a+i);
        a[i+n] = a[i];
    }
    for(int i=n+n;i>=1;--i) {
        int j = i + 1;
        while(j <= n+n && a[j] <= a[i]) j = R[j];
        R[i] = j;
        
        j = i + 1;
        while(j <= n + n && a[j] < a[i]) j = RE[j];
        RE[i] = j;
    }
    
    add( a[n+n]);
    long long total = 0;
    for(int i=n+n-1;i>=1;--i) {
        int id = lower_bound( list, list + nl, a[i], greater<int>()) - list;
        F[i] = nl - id;
        if(id > 0) ++F[i];
        add(a[i]);
        
        if(i <= n) total += F[i];
    }
    
    int maxx = 0;
    for(int i=1;i<=n;++i) if(maxx < a[i]) maxx = a[i];
    int dem = 0;
    for(int i=1;i<=n;++i) if(maxx == a[i]) ++ dem;
    int max2 = 0;
    for(int i=1;i<=n;++i) if(a[i] != maxx && max2 < a[i]) max2 = a[i];
    int dem2 = 0;
    for(int i=1;i<=n;++i) if(a[i] == max2) ++dem2;
    
    if(dem >= 2) {
        total -= dem * (long long) dem;
    }
    else {
        total -- ;
        if(dem2 == 1) --total;
        else if(dem2 > 1) total -= dem2;
    }
    cout << total << endl;
    return 0;
}