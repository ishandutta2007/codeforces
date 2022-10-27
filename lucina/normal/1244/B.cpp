#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int ans;
char s[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        scanf("%s", s + 1);
        ans = n;
        for(int i = 1 ;i <= n ;i ++){
            if(s[i] == '1'){
                ans = max(ans, 2 * i);
                ans = max(ans, n + 1);
                int res = n - i + 1;
                ans = max(ans, 2 * res);
            }
        }
        printf("%d\n",ans);
    }
}
/*
    Virtual Round 592
*/