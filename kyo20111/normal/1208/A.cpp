#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,b,c;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&c);
        c %= 3;
        printf("%d\n",c == 0 ? a : c == 1 ? b : a ^ b);
    }
}