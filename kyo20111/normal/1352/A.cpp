#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        vector<int> v;
        int n, d = 1;
        scanf("%d",&n);
        while(n){
            if(n % 10) v.push_back(n%10 * d);
            d *= 10, n /= 10;
        }
        printf("%d\n",v.size());
        for(int x : v) printf("%d ",x);
        puts("");
    }
}