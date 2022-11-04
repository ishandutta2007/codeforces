#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, a, b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",min({a, b, (a+b)/3}));
    }
}