#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,a[maxn],b[maxn];
bool s[maxn];


int main(){
    scanf("%d",&n);
    int ans = 0;
    for(int i=1;i<=n;i++)
    scanf("%1d",&s[i]),ans+=s[i];
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int k=1;k<=1000;k++){
            int ct = 0;
        for(int i=1;i<=n;i++){
            int shift = (k - b[i]) /a[i] + 1;
            if(k < b[i]) shift = 0;
            ct += (s[i] ^ (shift & 1));
        }
        ans =max(ans,ct);
    }
    printf("%d\n",ans);

}
/*
    Good Luck
        -Lucina
*/