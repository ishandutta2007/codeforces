#include<bits/stdc++.h>
using namespace std;
int const maxn = 3e5 + 10;
int n;
char a[maxn], b[maxn];
bool inversion(char x[]){
    bool res = true;
    for(int i =  1;i <= n ;i ++){
        for(int j = 1 ;j < i ; j ++){
            if(x[i] < x[j])
                res ^= 1;
        }
    }
    return res;
}

bool solve(){
    scanf("%d %s %s", &n, a + 1 , b + 1);
    vector<int> ct(26);
    bool much = false;
    for(int i = 1 ;i <= n ; i ++){
        ct[a[i] - 'a'] ++ ;
        if(ct[a[i] - 'a'] > 1)
            much = true;
    }
    ///duplicate character guarantee true
    for(int i = 1 ; i <=  n; i++){
        ct[b[i] - 'a'] --;
    }
    for(int i = 0 ;i < 26 ; i ++)
        if(ct[i]) return false;
    if(much) return true;    
    /// the rest is just permutation
    return inversion(a) == inversion(b);
}

int main(){
    int T;
    for(scanf("%d",&T); T -- ;){
        printf(solve() ? "YES\n" : "NO\n");
    }
}