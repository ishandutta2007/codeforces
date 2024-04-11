#include<bits/stdc++.h>
using namespace std;
int solve(){
    int sum = 0,n ,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x),sum += x;
    return ((sum - 1) / n + 1);
}

int main(){
    int q;
    cin >>q;
    while(q--){
        printf("%d\n",solve());
    }
}