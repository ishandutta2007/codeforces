#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
int n, a[nax];
bool solve(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n; i ++)
        scanf("%d", a + i);
    long long cur = 0;
    for(int i = 1 ;i < n; i ++){
        cur += a[i];
        if(cur <= 0) return false;
    }
    cur = 0;
    for(int i = n ;i > 1 ; i --){
        cur += a[i];
        if(cur <= 0) return false;
    }
    return true;
}

int main(){
    int T;
    for(cin >> T ; T -- ;){
        puts(solve() ?  "YES" : "NO");
    }
}