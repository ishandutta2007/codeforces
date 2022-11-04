#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define all(x) (x).begin(), (x).end()
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n == 1){
            puts("-1");
            continue;
        }
        
        n--;
        if(n%3 == 0){
            printf("3");
            n--;
        }
        for(int i=1;i<=n;i++) printf("2");
        int b = 3;
        __int128 a = b;
        if(a != b) return !printf("111");
        puts("3");
    }
}