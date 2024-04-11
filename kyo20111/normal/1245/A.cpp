#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        int a,b; scanf("%d %d",&a,&b);
        printf("%s\n",__gcd(a,b) > 1 ? "Infinite" : "Finite");
    }
}