#include<bits/stdc++.h>
using namespace std;
int const maxn = 300010;
char s[maxn];
int n, a, b;
bool solve(){
    scanf("%d %d %s", &a ,&b, s + 1);
    n = strlen(s + 1);
    int cur = 0;
    vector<int> all;
    for(int i = 1 ;i <= n; i++){
        if(s[i] == 'X'){
            if(cur > 0 && cur >= b) all.push_back(cur);
            cur = 0;
        }
        else{
            cur ++ ;
        }
    }
    if(cur > 0 && cur >= b) all.push_back(cur);
    /**
    Obviously, this game Bob has much more advantage.
    Then, let's see when Bob will win.
    1) If there is block with length b <= x < a -> Bob win
    2) If there are 2 or more blocks with length >= 2b , Bob can make it to condition one
    3) every block length < 2*b ? In each block, basically at most one person can place, then it's just parity
    4) Exactly one block with length >= 2*b, determine brute-force_ly. Obviously he can't make it fall into
    category 1) and 2) So determine if he can pull it to condition three and consider parity.
    */
    for(int i: all){
        if(i >= b && i < a) return false;
    }
    int ct = 0 , block = 0;
    for(int i:all){
        if(i >= 2*b){
            ct ++ ; block = i;
        }
    }
    if(ct > 1) return false;
    if(ct == 0){
        return (int)all.size() % 2;
    }
    if(ct == 1){
        int split1 ,  split2 ;
        for(int i = 1 ;i + a - 1 <= block ;i++){
            split1 = i - 1;
            split2 = block - (i + a - 1);
            if(split1 >= b && split1 < a) continue;
            if(split2 >= b && split2 < a) continue;
            if(split1 >= 2 *b || split2 >= 2*b)continue;
            int tot = (int)all.size() - 1 + (split1 >= a) + (split2 >= a);
            if(tot % 2 == 0)return true;
        }
    }
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while( t-- ){
        printf(solve() ? "YES\n" : "NO\n");
    }
}