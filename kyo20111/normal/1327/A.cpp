#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, k, m, s[100100];
int main(){
    s[1] = 1;
    int pl = 3;
    for(m=2;;m++){
        s[m] = s[m-1] + pl;
        if(s[m] >= 10000000) break;
        pl += 2;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        if(m < k || s[k] > n || ((k&1) ^ (n&1))){
            puts("NO");
            continue;
        }
        puts("YES");
    }
}