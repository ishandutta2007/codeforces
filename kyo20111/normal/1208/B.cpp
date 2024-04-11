#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[2020],cnt,ans=1e9;
unordered_map<int,int> mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) mp[a[i]]++;

    for(auto it : mp) if(it.second > 1) cnt++;

    if(!cnt) return !printf("0");

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(--mp[a[j]] == 1){
                if(--cnt == 0) ans = min(ans, j-i+1);
            }
        }

        for(int j=i;j<=n;j++) if(++mp[a[j]] == 2) cnt++;
    }

    printf("%d",ans);
}