#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;

int main(){
    int t;
    cin >> t;
    while( t--){
        int a , b , c , d , k;
        cin >> a >> b >> c >> d >> k;
        int pen = (a-1) / c + 1, pencil = (b - 1) / d + 1;
        if(pen + pencil <= k){
            printf("%d %d\n", pen, pencil);
        }
        else printf("-1\n");
    }

}
/*
    Virtual Round 592
*/