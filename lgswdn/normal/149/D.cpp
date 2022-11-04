#include<bits/stdc++.h>
#define int long long
#define rev(a) (cr==1?2:1)
#define int long long
#define rep2(i) for(int i=0;i<=2;i++)

using namespace std;
const int N=709,mod=1000000007;

int n,match[N],f[N][N][3][3];
int dfs(int l,int r,int cl,int cr) {
    if(f[l][r][cl][cr]!=-1) return f[l][r][cl][cr]; 
    else if(r-l==1) return f[l][r][cl][cr]=(cl>0)!=(cr>0);

    f[l][r][cl][cr]=0;
    if(match[l]==r) {
        if(!cl&&!cr||cl&&cr) return f[l][r][cl][cr]=0;
        else if(cl==0)
            return f[l][r][cl][cr]=(dfs(l+1,r-1,1,0)+dfs(l+1,r-1,2,0)
                            +dfs(l+1,r-1,0,rev(cr))
                            +dfs(l+1,r-1,1,rev(cr))
                            +dfs(l+1,r-1,2,rev(cr))
                            +dfs(l+1,r-1,0,0))%mod;
        else if(cr==0)
            return f[l][r][cl][cr]=(dfs(l+1,r-1,0,1)+dfs(l+1,r-1,0,2)
                            +dfs(l+1,r-1,rev(cl),0)
                            +dfs(l+1,r-1,rev(cl),1)
                            +dfs(l+1,r-1,rev(cl),2)
                            +dfs(l+1,r-1,0,0))%mod;
    } else {
        rep2(i) rep2(j) f[l][r][i][j]=0;
        rep2(i) rep2(j) rep2(k) rep2(p)
            if(j&&k&&(j==k)) continue;
            else (f[l][r][i][p]+=dfs(l,match[l],i,j)*dfs(match[l]+1,r,k,p))%=mod;
        return f[l][r][cl][cr];
    }
}

char s[N];
signed main() {
    memset(f,-1,sizeof(f));
    scanf("%s",s+1); int n=strlen(s+1);
    stack<int>st;
    for(int i=1;i<=n;i++) {
        if(s[i]=='(') st.push(i);
        else match[st.top()]=i,st.pop();
    }
    int ans=0;
    rep2(i) rep2(j) (ans+=dfs(1,n,i,j))%=mod;
    printf("%lld",ans);
    return 0;
}