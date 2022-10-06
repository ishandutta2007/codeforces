#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;

ll dfs(ll n){
    if(n==0)return 0;
    if(n==4)return 3;
    if(n%2==0){
        if((n/2)%2==0){
            return 1 + dfs(n-2);
        }else{
            return n - dfs(n/2);
        }
    }else{
        return n - dfs(n-1);
    }
}

int main(){
    int t;
    cin >> t;
    rep(i,t){
        ll n;
        cin >> n;
        cout << dfs(n) << "\n";
    }


    return 0;
}