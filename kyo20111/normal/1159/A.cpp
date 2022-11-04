#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt;
char s[111];
int main(){
    scanf("%d %s",&n,s);
    for(int i=0;i<n;i++){
        if(s[i] == '-') cnt = max(cnt-1, 0);
        else cnt++;
    }
    printf("%d",cnt);
}