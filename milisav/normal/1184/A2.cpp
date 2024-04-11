#include<bits/stdc++.h>
using namespace std;
int n;
char y[300000];
bool pos[300000];
int main() {
    scanf("%d",&n);
    scanf("%s",y);
    for(int i=1;i<=n;i++){
        if(n%i==0) {
            pos[i]=true;
            for(int j=0;j<i;j++) {
                int x=0;
                for(int k=j;k<n;k+=i) {
                    if(y[k]=='1') x^=1;
                }
                if(x!=0) {
                    pos[i]=false;
                    break;
                }
            }
        }
    }
    int r=0;
    for(int i=1;i<=n;i++) {
        if(pos[__gcd(n,i)]) r++;
    }
    printf("%d",r);
    return 0;
}