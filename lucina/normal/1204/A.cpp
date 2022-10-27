#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
using ld = __float128;
string s;

int main(){
    ld res = 0;
    cin >> s;
    for(char c : s){
        res *= 2;
        res += (c - '0');
    }
    ld now = 1;
    int ans = 0;
    while(now < res){
        now *= 4;
        ans += 1;
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/