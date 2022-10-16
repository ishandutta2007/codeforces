#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100010;
int n, sum[N], ans;
char s[N];
int main(){
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1];
        if(s[i] == 'G') sum[i]++;
    }
    for(int i = 1; i <= n; i++){
        if(s[i] == 'S'){
            int ansLeft, ansRight;
            int lenLeft, lenRight;
            //
            int l = 0, r = (i - 1);
            while(l < r){
                int mid = (l + r + 1) >> 1;
                int left = (i - 1) - mid + 1;
                if(sum[i - 1] - sum[left - 1] == mid) l = mid;
                else r = mid - 1;
            }
            lenLeft = r; ansLeft = (i - 1) - r + 1;

            //
            l = 0, r = n - (i + 1) + 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                int right = (i + 1) + mid - 1;
                if(sum[right] - sum[i] == mid) l = mid;
                else r = mid - 1;
            }
            lenRight = r; ansRight = (i + 1) + r - 1;

            if(sum[ansLeft - 1] || sum[n] - sum[ansRight]) 
                ans = max(ans, lenRight + lenLeft + 1);
            else ans = max(ans, lenLeft + lenRight);
        }
        
    }
    if(sum[n] == n) ans = n;
    printf("%d\n", ans);
    return 0;
}