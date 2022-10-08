#include <iostream>
#include <cstring>
using namespace std;

int n;
long long F[55][2][2];
long long F2[55][2][2], F3[55][2][2];
long long k;
int a[55], na;


long long calc( int i, int j, int nguoclonhon, int daolonhon) {
    if(i > j) return 1;
    if(i == j) {
        if(daolonhon) return 2;
        else return 1;
    }
    long long &ret = F[i][nguoclonhon][daolonhon];
    if(ret != -1) return ret;
    ret = 0;
    for(int left=0;left<2;++left) {
        for(int right=0;right<2;++right) {
            if((nguoclonhon || left <= right) && (daolonhon || left <= 1-right)) {
                ret += calc( i + 1, j - 1, nguoclonhon || left < right, daolonhon || left < 1-right);
            }
        }
    }
    return ret;
}


long long calc2(int i, int j, int nguoclonhon, int daolonhon) {
    if(i > j) return 1;
    if(i == j) {
        if(daolonhon) { if(i < na) return 1; else return 2; }
        else { if((i < na && a[i] == 0) || i >= na) return 1; else return 0; }
    }
    long long &ret = F2[i][nguoclonhon][daolonhon];
    if(ret != -1) return ret;
    ret = 0;
    for(int left=0;left<2;++left) if(i >= na || a[i] == left) {
        for(int right=0;right<2;++right) {
            if((nguoclonhon || left <= right) && (daolonhon || left <= 1-right)) {
                ret += calc2( i + 1, j - 1, nguoclonhon || left < right, daolonhon || left < 1-right);
            }
        }
    }
    return ret;
}   

long long calc3( int pos, int nguoclonhon, int daolonhon) {
    if(pos == n) return (nguoclonhon == 0 && daolonhon == 0);
    long long &ret = F3[pos][nguoclonhon][daolonhon];
    if(ret != -1) return ret;
    ret = 0;
    for(int x=0;x<2;++x) if(pos >= na || a[pos] == x) {
        ret += calc3( pos + 1, (x > a[n-pos-1]) ? 0 : (x < a[n-pos-1] ? 1 : nguoclonhon), ((1-x) > a[n-pos-1]) ? 0 : ((1-x) < a[n-pos-1] ? 1 : daolonhon) );
    }
    return ret;
}

int main() {    
    cin >> n >> k;
    memset( F, -1, sizeof(F));
    long long res = calc( 0, n - 1, 0, 0);  
    if(res <= k) { cout << -1 << endl; return 0; }
    for(int i=0;i<(n+1)/2;++i) {
        a[i] = 0;
        na = i+1;
        memset( F2, -1, sizeof(F2));
        long long z = calc2( 0, n - 1, 0, 0);
        if(k < z) continue;
        else {
            k -= z;
            a[i] = 1;
            na = i + 1;
        }
    }
    for(int i=(n+1)/2;i<n;++i) {
        a[i] = 0;
        na = i + 1;
        memset( F3, -1, sizeof(F3));
        long long z = calc3( (n+1)/2, 0, (n % 2 == 1 && (a[n/2] == 1)) ? 1 : 0);
        if( k < z ) continue;
        else {
            k -= z;
            a[i] = 1;
            na = i + 1;
        }
    }
    for(int i=0;i<n;++i) cout << a[i] ; cout << endl;
    return 0; 
}