#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,mnx[256],mxx[256],mny[256],mxy[256],chk[256];
char mp[2020][2020];
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i='a';i<='z';i++) mnx[i]=mny[i]=1e9;
        for(int i='a';i<='z';i++) mxx[i]=mxy[i]=chk[i]=0;
        int k=0,x=0,y=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j] != '.'){
                    if(k < mp[i][j]){
                        k = mp[i][j];
                        x=i, y=j;
                    }
                    mnx[mp[i][j]] = min(mnx[mp[i][j]], i);
                    mxx[mp[i][j]] = max(mxx[mp[i][j]], i);
                    mny[mp[i][j]] = min(mny[mp[i][j]], j);
                    mxy[mp[i][j]] = max(mxy[mp[i][j]], j);
                    chk[mp[i][j]] = 1;
                }
            }
        }
        int fl=0;
        for(int i='a';i<=k;i++){
            if(mnx[i] != mxx[i] && mny[i] != mxy[i]){
                if(chk[i]) fl=1;
            }else if(mnx[i] != mxx[i]){
                for(int j=mnx[i];j<=mxx[i];j++){
                    if(mp[j][mny[i]] == '.' || (mp[j][mny[i]] != '.' && (mp[j][mny[i]] < i))){
                        fl=1;
                        break;
                    }
                }
            }else if(mny[i] != mxy[i]){
                for(int j=mny[i];j<=mxy[i];j++){
                    if(mp[mnx[i]][j] == '.' || (mp[mnx[i]][j] != '.' && (mp[mnx[i]][j] < i))){
                        fl=1;
                        break;
                    }
                }
            }

            if(fl) break;
        }
        if(fl) printf("NO\n");
        else if(!k) printf("YES\n0\n");
        else{
            printf("YES\n%d\n",k-'a'+1);
            for(int i='a';i<=k;i++){
                if(!chk[i]) printf("%d %d %d %d\n",x,y,x,y);
                else printf("%d %d %d %d\n",mnx[i],mny[i],mxx[i],mxy[i]);
            }
        }
    }
}