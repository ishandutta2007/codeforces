#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

char str[333333];
int A,B;
int N;
void solve(){
    scanf("%lld%lld",&A,&B);
    scanf("%s",str);
    N=strlen(str);
    
    int num=0,uku=-1;
    bool flag=false;
    int cur=0;
    while(cur<N){
        if(str[cur]=='X'){
            cur++;
            continue;
        }
        int nex=cur;
        while(nex<N&&str[nex]=='.')nex++;
        int l=nex-cur;
        
        cur=nex;
        
        
        if(l<B)continue;
        if(l<A){
            flag=true;
            continue;
        }
        if(l<2*B){
            num++;
            continue;
        }
        if(uku==-1){
            uku=l;
            continue;
        }
        flag=true;
    }
    
    if(flag){
        puts("NO");
        return;
    }
    
    bool win=false;
    if(uku==-1){
        if(num&1)win=true;
    }
    else{
        for(int x=0;x+A<=uku;x++){
            int y=uku-A-x;
            int nn=num;
            if(x>=B&&x<A)continue;
            if(y>=B&&y<A)continue;
            if(x>=2*B)continue;
            if(y>=2*B)continue;
            if(x>=A)nn++;
            if(y>=A)nn++;
            if(nn%2==0)win=true;
        }
    }
    if(win)puts("YES");
    else puts("NO");
}

signed main(){
    int Q;scanf("%lld",&Q);
    while(Q--){
        solve();
    }
    
    return 0;
}