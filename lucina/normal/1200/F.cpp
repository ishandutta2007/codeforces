#include<bits/stdc++.h>
using namespace std;
const int maxn=1010,l=2520;
void fix(int &x){
    x%=l;if(x<0)x+=l;return;
}
int n,k[maxn],m[maxn];
int out[maxn][12],f[maxn][l+5];
bool v[maxn][l+5],vis[maxn];
vector<pair<int,int>> st;

int rec(int x,int y){
    if(f[x][y]>0)return f[x][y];
    if(v[x][y]){
        vector<int> ret;
        int c=0;
        while(st.back().first!=x||st.back().second!=y){
            if(!vis[st.back().first]){
                vis[st.back().first]=true;
                ret.push_back(st.back().first);
                ++c;
            }
            st.pop_back();
        }
        assert(st.back().first==x);
        if(!vis[x]){
            vis[x]=true;
            ret.push_back(x);
            ++c;
        }
        for(int i:ret)vis[i]=false;
        return f[x][y]=c;
    }
    v[x][y]=true;
    st.push_back({x,y});
    return f[x][y]=rec(out[x][(y+k[x])%m[x]],(y+k[x])%l);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        fix(k[i]);
    }
    st.reserve(2520*n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m[i]);
        for(int j=0;j<m[i];j++){
            scanf("%d",&out[i][j]);
        }
    }
    int q,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&x,&y);
        fix(y);
        st.clear();
        printf("%d\n",rec(x,y));
    }
}
/*
    Good Luck
        -Lucina
*/