#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

int a[100100],t[400400][6],mid[400400][6],mark[400400],sm[100100][6],cnk[7][7],mk[100100][6];

int deg(int a,int d){
    int ans=1;
    while(d>0){
        ans=(ll)ans*a%mod;
        d--;
    }
    return ans;
}

void build(int v,int l,int r){
    if(l==r){
        mark[v]=a[l];
        t[v][0]=t[v][1]=t[v][2]=t[v][3]=t[v][4]=t[v][5]=a[l];
        return;
    }
    mark[v]=-1;
    int m=(l+r)/2,i,j,tmp=1;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    For(i,6){
        mid[v][i]=tmp;
        tmp=(ll)tmp*(m-l+1)%mod;
    }
    For(i,6){
        t[v][i]=t[2*v][i]+t[2*v+1][i];
        t[v][i]%=mod;
        For(j,i){
            t[v][i]+=(ll)mid[v][i-j]*t[2*v+1][j]%mod*cnk[i][i-j]%mod;
            t[v][i]%=mod;
        }
    }
}

void modify(int v,int l,int r,int l1,int r1,int u){
    if(l1>r1) return;
    int i,j;
    if(l==l1&&r==r1){
        For(i,6){
            t[v][i]=(ll)u*sm[r-l+1][i]%mod;
        }
        mark[v]=u;
        return;
    }
    int m=(l+r)/2;
    if(mark[v]!=-1){
        modify(2*v,l,m,l,m,mark[v]);
        modify(2*v+1,m+1,r,m+1,r,mark[v]);
        mark[v]=-1;
    }
    modify(2*v,l,m,l1,min(r1,m),u);
    modify(2*v+1,m+1,r,max(l1,m+1),r1,u);
    For(i,6){
        t[v][i]=t[2*v][i]+t[2*v+1][i];
        t[v][i]%=mod;
        For(j,i){
            t[v][i]+=(ll)mid[v][i-j]*t[2*v+1][j]%mod*cnk[i][i-j]%mod;
            t[v][i]%=mod;
        }
    }
}



vector<int> ask(int v,int l,int r,int l1,int r1){
    int i;
    vector<int> ans;
    if(mark[v]!=-1){
        For(i,6){
            ans.pb((ll)mark[v]*sm[r1-l1+1][i]%mod);
        }
        return ans;
    }
    if(l1==l&&r1==r){
        For(i,6){
            ans.pb(t[v][i]);
        }
        return ans;
    }
    vector<int> v1,v2;
    int m=(l+r)/2,j;
    if(r1>m){
        v2=ask(2*v+1,m+1,r,max(l1,m+1),r1);
    }
    if(l1<=m){
        v1=ask(2*v,l,m,l1,min(m,r1));
    }
    if(v1.size()==0){
        return v2;
    }
    if(v2.size()==0){
        return v1;
    }
    ans.assign(6,0);
    For(i,6){
        ans[i]=v1[i]+v2[i];
        ans[i]%=mod;
        For(j,i){
            ans[i]+=(ll)v2[j]*mk[m-l1+1][i-j]%mod*cnk[i][i-j]%mod;
            ans[i]%=mod;
        }
    }
    return ans;
}

void solve(int n){
    int i,j,m,l,r,k,tmp;
    scanf("%d",&m);
    For(i,n){
        scanf("%d",&a[i]);
    }
    For(i,6){
        cnk[0][i]=0;
        cnk[i][0]=1;
        sm[0][i]=0;
        mk[0][i]=0;
    }
    FOR(i,1,n+1){
        tmp=1;
        For(j,6){
            mk[i][j]=tmp;
            sm[i][j]=sm[i-1][j]+tmp;
            sm[i][j]%=mod;
            tmp=(ll)tmp*i%mod;
        }
    }
    FOR(i,1,6){
        FOR(j,1,i+1){
            cnk[i][j]=cnk[i-1][j-1]+cnk[i-1][j];
        }
    }
    getchar();
    build(1,0,n-1);
    For(i,m){
        if(getchar()=='='){
            scanf("%d%d%d",&l,&r,&k);
            modify(1,0,n-1,l-1,r-1,k);
        }
        else{
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",ask(1,0,n-1,l-1,r-1)[k]);
        }
        getchar();
    }



}



int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[100100];
    string s;
    while(scanf("%d",&n)==1){
        solve(n);
    }




    return 0;
}