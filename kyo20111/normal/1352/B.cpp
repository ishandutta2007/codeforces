#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);

        if(n >= (k-1) && (n - (k-1)) % 2){
            puts("YES");
            for(int i=1;i<k;i++) printf("1 ");
            printf("%d\n",n - (k-1));
            continue;
        }

        if(n >= k*2 && (n - (k-1)*2) % 2 == 0){
            puts("YES");
            for(int i=1;i<k;i++) printf("2 ");
            printf("%d\n",n - (k-1)*2);
            continue;
        }

        puts("NO");
    }
}