#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, c, a[2];
char s[1001001], t[1001001];
int main(){
    scanf("%d %s %s",&n,s+1,t+1);
    for(int i=1;i<=n;i++) if(s[i] == '1') c++;
    for(int i=1;i<=n;i++) if(t[i] == '1') c--;
    if(c) return !printf("-1");
    
    for(int i=1;i<=n;i++){
        if(s[i] != t[i]){
            int f = (s[i] == '1');
            if(a[!f]) a[!f]--, c--;
            a[f]++, c++;
        }
    }
    printf("%d",c);
}