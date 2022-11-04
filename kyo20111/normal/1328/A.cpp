#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a, b; scanf("%d %d",&a,&b);
        int c = (a / b + (a % b ? 1 : 0)) * b;
        printf("%d\n",c-a);
    }
}