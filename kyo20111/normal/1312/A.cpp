#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int a, b; scanf("%d %d",&a,&b);
        puts(a%b ? "NO" : "YES");
    }
}