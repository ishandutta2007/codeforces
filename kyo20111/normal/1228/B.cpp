#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,r[1010],c[1010],mp[1010][1010],ans=1,mod=1e9+7;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) mp[i][j] = -1;
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=r[i];j++) mp[i][j] = 1;
    	mp[i][r[i]+1] = 0;
    }

    for(int j=1;j<=m;j++){
    	for(int i=1;i<=c[j];i++){
    		if(mp[i][j] == 0) return !printf("0");
    		mp[i][j] = 1;
    	}
    	if(mp[c[j]+1][j] == 1) return !printf("0");
    	mp[c[j]+1][j] = 0;
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == -1) ans = ans*2 % mod;
    printf("%d",ans);
}