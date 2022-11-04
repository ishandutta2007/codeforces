#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, cnt[300];
char s[200200];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf(" %s",s);

        cnt['1'] = cnt['2'] = cnt['3'] = 0;
        int mn = 1e9;
        int l = 0, r = -1, n = strlen(s);
        while(r < n){
            if(cnt['1'] && cnt['2'] && cnt['3']){
                mn = min(mn, r - l + 1);
                cnt[s[l]]--;
                l++;
            }else{
                r++;
                cnt[s[r]]++;
            }
        }
        while(cnt['1'] && cnt['2'] && cnt['3']){
            mn = min(mn, r - l + 1);
            cnt[s[l]]--;
            l++;
        }
        if(mn > n) puts("0");
        else printf("%d\n",mn);
    }
}