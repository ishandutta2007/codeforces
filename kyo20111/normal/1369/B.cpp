#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;
char s[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int l = 1, cnt = 0;
        while(l <= n && s[l] == '0') printf("0"), l++;
        if(l > n){
            puts("");
            continue;
        }
        for(int i=l;i<=n;i++){
            if(s[i] == '0') cnt = 0;
            else cnt++;
        }
        if(cnt != n-l+1) printf("0");
        for(int i=1;i<=cnt;i++) printf("1");
        puts("");
    }
}