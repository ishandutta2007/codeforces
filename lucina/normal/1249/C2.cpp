#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(){
    ll n;
    scanf("%lld", &n);
    vector<int> a;
    while(n > 0){
        a.push_back(n % 3);
        n /= 3;
    }
    reverse(a.begin(), a.end());
    int top = 0;
    for(int i = 0 ; i < (int)a.size() ; i++){
        if(a[i] == 2){
                for(int j = i + 1 ; j <(int)a.size() ; j++)
                a[j] = 0;
            for(int j = i ; j >= 0 ;j --){
                if(top){
                    a[j] ++;
                }
                top = 0;
                if(a[j] == 2){
                    a[j] = 0;
                    top = 1;
                }
            }
        }
    }
    reverse(a.begin(), a.end());
    a.push_back(top);
    ll cur = 1, ans = 0;
    for(int i : a){
        ans += cur * i;
        assert(i < 2);
        cur *=3;
    }
    return ans;
}

int main(){
    int q;
    for(cin >> q; q -- ;){
        printf("%lld\n", solve());
    }
}