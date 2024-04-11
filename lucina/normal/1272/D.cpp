#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int a[nax], n;
int pre[nax], suf[nax];

int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i ++)
        scanf("%d", a + i);
    for(int i = 1 ;i <= n;i ++ ){
        int j = i + 1;
        while(j <= n && a[j] > a[j - 1]) j ++;
        for(int k = j - 1 ; k >= i ;k --){
            pre[k] = k - i + 1;
        }
        i = j -1;
    }
    for(int i = n ;i >= 1 ; i --){
        int j = i - 1;
        while(j > 0 && a[j] < a[j + 1]) j --;
        for(int k = i ; k > j ; k --)
            suf[k] = i - k + 1;
        i = j + 1;
    }
    int ans = 0;
    for(int i = 1; i<= n; i ++){
        int res = pre[i];
        if(i + 2 <= n && a[i + 2] > a[i])
            res += suf[i + 2];
        ans = max(ans, res);
        ans = max(ans, pre[i]);
        ans = max(ans, suf[i]);
    //    printf("%d ", res );
    }
    //cerr << endl;
    //for(int i = 1;i <= n ;i ++)
    //    printf("%d%c", pre[i], i == n ? '\n' : ' ');

    //for(int i = 1;i <= n ;i ++)
    //    printf("%d%c", suf[i], i == n ? '\n' : ' ');
    printf("%d\n", ans);
}