#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200010;
int n, tx, ty, x[N], y[N];
char str[N];
bool inline check(int len){
    for(int l = 1, r = len; r <= n; l++, r++){
        int nx = x[n] - (x[r] - x[l - 1]);
        int ny = y[n] - (y[r] - y[l - 1]);
        int dist = abs(tx - nx) + abs(ty - ny);
        if(len >= dist && (dist & 1) == (len & 1)) return true;
    }
    return false;
}
int main(){
    scanf("%d%s%d%d", &n, str + 1, &tx, &ty);
    for(int i = 1; i <= n; i++){
        x[i] = x[i - 1], y[i] = y[i - 1];
        if(str[i] == 'U') y[i]++;
        else if(str[i] == 'D') y[i]--;
        else if(str[i] == 'L') x[i]--;
        else if(str[i] == 'R') x[i]++;
    }
    if(!check(n)) puts("-1");
    else{
        int l = 0, r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d", r);
    }
    
    return 0;
}