#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

vector<vector<ll>> operator*(vector<vector<ll>> &m1,vector<vector<ll>> &m2){
    vector<ll> one(m2[0].size(),0);
    vector<vector<ll>> ans(m1.size(),one);
    ll n=m2.size(),i,j,r,a=ans.size(),b=ans[0].size();
    For(i,a){
        For(j,b){
            For(r,n){
                ans[i][j]+=m1[i][r]*m2[r][j];
                ans[i][j]%=mod;
            }
        }
    }
    return ans;
}

void print(vector<vector<ll>> &m){
    int i,j,a=m.size(),b=m[0].size();
    For(i,a){
        For(j,b){
            printf("%I64d ",m[i][j]);
        }
        printf("\n");
    }
}

vector<vector<ll>> deg(vector<vector<ll>> &v,int d){
    int a=1;
    while((a<<2)<=d){
        a=(a<<1);
    }
    if(d==1) return v;
    vector<vector<ll>> ans=v;
    while(a>0){
        ans=ans*ans;
        if(a&d){
            ans=ans*v;
        }
        a=(a>>1);
    }
    return ans;
}





void solve(int n){
    int i,j,l[111],d,a;
    vector<ll> one(101,0),two(1,0);
    vector<vector<ll>> b(101,one),ans(101,two);
    scanf("%d",&d);
    For(i,111){
        l[i]=0;
    }
    For(i,n){
        scanf("%d",&a);
        l[a]++;
    }
    For(i,99){
        For(j,101){
            if(j==i+1) b[i][j]=1;
        }
    }
    FOR(i,99,101){
        For(j,101){
            b[i][j]=l[100-j];
        }
    }
    b[100][100]=1;
    if(d==0){
        printf("1");
        return;
    }
    For(i,99){
        ans[i][0]=0;
    }
    ans[99][0]=ans[100][0]=1;
    ans=deg(b,d)*ans;
    printf("%I64d",ans[100][0]);




#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}