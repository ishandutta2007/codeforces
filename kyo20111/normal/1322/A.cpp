#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, ans;
char s[1001001];
int main(){
    scanf("%d %s",&n,s+1);
    if(n % 2) return !printf("-1");
    int st = 0, fl = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '(') st++;
        else st--;

        if(!fl && st < 0){
            fl = i;
        }

        if(fl && st == 0){
            ans += i - fl + 1;
            fl = 0;
        }
    }
    if(st) return !printf("-1");

    printf("%d",ans);
}