#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
char mp[555][555];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf(" %c",&mp[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j] == 'X' && mp[i-1][j-1]=='X' && mp[i-1][j+1]=='X' && mp[i+1][j-1] == 'X' && mp[i+1][j+1] == 'X') ans++;
        }
    }
    printf("%d",ans);
}