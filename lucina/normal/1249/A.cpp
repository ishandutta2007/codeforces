#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[105];
int doo(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1 ;i <= n ;i++)
    cin >> a[i];
    sort(a + 1 ,  a + 1 + n);
    for(int i = 2 ;i <= n; i++){
        if(a[i] == a[i-1] + 1)
        return 2;
    }
    return 1;
}

int main(){
    int q;
    for(cin >> q; q -- ; ){
        printf("%d\n",doo());
    }
    
}