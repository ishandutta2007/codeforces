#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,x,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&n,&x,&a,&b);
        if(a > b) swap(a, b);
        while(a > 1 && x) a--,x--;
        while(b < n && x) b++,x--;
        printf("%d\n",b-a);
    }
}