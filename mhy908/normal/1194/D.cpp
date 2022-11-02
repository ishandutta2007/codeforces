#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int w, n, k;
int main()
{
    scanf("%d", &w);
    for(int u=1; u<=w; u++){
        scanf("%d %d", &n, &k);
        if(n==0)printf("Bob\n");
        else if(k%3){
            if(n%3)printf("Alice\n");
            else printf("Bob\n");
        }
        else{
            n%=k+1;
            if(n==k||n%3)printf("Alice\n");
            else printf("Bob\n");
        }
    }
}