// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

char a[1005][1005];
array<int,3> two[10][10],three[10][10][10];
int dp[1005],from[1005],len[1005];
int n,m;

void solve(){
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%s",a[i]+1);
    }
    scanf("%s",a[0]+1);
    rep(i,0,n){
        rep(j,1,m)a[i][j]-='0';
    }
    rep(i,0,9){
        rep(j,0,9){
            two[i][j]={-1,-1,-1};
            rep(k,0,9){
                three[i][j][k]={-1,-1,-1};
            }
        }
    }
//    cerr<<"!!\n";
    
    rep(i,1,n){
        rep(j,1,m-1){
            two[a[i][j]][a[i][j+1]]={j,j+1,i};
        }
        rep(j,1,m-2){
            three[a[i][j]][a[i][j+1]][a[i][j+2]]={j,j+2,i}; 
        }
    }
//    cerr<<"!\n";
    
    rep(i,0,m)dp[i]=0;
    dp[0]=1;
    rep(j,1,m){
        if(j>=2&&two[a[0][j-1]][a[0][j]][0]!=-1&&dp[j-2]){
            dp[j]=1,from[j]=j-2;
        }
        if(j>=3&&three[a[0][j-2]][a[0][j-1]][a[0][j]][0]!=-1&&dp[j-3]){
            dp[j]=1,from[j]=j-3;
        }
    }
    if(!dp[m]){
        puts("-1");
        return; 
    }
//    cerr<<"!\n";
    vector<array<int,3>>ans;
    for(int i=m;i;i=from[i]){
        if(from[i]==i-2){
            ans.pb(two[a[0][i-1]][a[0][i]]);
        }else{
            ans.pb(three[a[0][i-2]][a[0][i-1]][a[0][i]]);
        }
    }
    print(SZ(ans),'\n');
    while(SZ(ans)){
        array<int,3>zz=ans.back();ans.pop_back();
        printf("%d %d %d\n",zz[0],zz[1],zz[2]); 
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}