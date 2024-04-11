#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

vector<vector<int>> sn;

ll d[80][80];

bool ins(int a,int l,int r){
    return a>=l&&a<r;
}

ll dp(int l,int r){
    if(d[l][r]!=-1) return d[l][r];
    d[l][r]=0;
    bool g=true;
    For(i,sn.size()){
        vector<int> s=sn[i];
        if(s[0]==l||s[0]==l+1){

            if(s[2]==1){
                if(!ins(s[1],l+2,r)) g=false;
            }
            if(s[2]==0){
                if(!ins(s[1],l,r)) g=false;
            }
            if(s[2]==-1){
                if(!(s[0]==l&&s[1]==l+1)){
                    g=false;
                }
            }
        }
        if(s[1]==l||s[1]==l+1){
            if(s[2]==1){
                if(ins(s[0],l,r)) g=false;
            }
            if(s[2]==0){
                if(ins(s[0],l+2,r)) g=false;
            }
            if(s[2]==-1){
                if(!(s[0]==l&&s[1]==l+1)){
                    g=false;
                }
            }
        }
    }
    if(r==l+2&&g) return d[l][r]=1;
    if(r==l+2) return 0;
    if(g) 
        d[l][r]+=dp(l+2,r);
    g=true;
    For(i,sn.size()){
        vector<int> s=sn[i];
        if(s[0]==l||s[0]==r-1){
            if(s[2]==1){
                if(!ins(s[1],l+1,r-1)) g=false;
            }
            if(s[2]==0){
                if(!ins(s[1],l,r)) g=false;
            }
            if(s[2]==-1){
                if(!(s[0]==l&&s[1]==r-1)){
                    g=false;
                }
            }
        }
        if(s[1]==l||s[1]==r-1){
            if(s[2]==1){
                if(ins(s[0],l,r)) g=false;
            }
            if(s[2]==0){
                if(ins(s[0],l+1,r-1)) g=false;
            }
            if(s[2]==-1){
                if(!(s[0]==l&&s[1]==r-1)){
                    g=false;
                }
            }
        }
    }
    if(g) 
        d[l][r]+=dp(l+1,r-1);
    g=true;
    For(i,sn.size()){
        vector<int> s=sn[i];
        if(s[0]==r-2||s[0]==r-1){
            if(s[2]==1){
                if(!ins(s[1],l,r-2)) g=false;
            }
            if(s[2]==0){
                if(!ins(s[1],l,r)) g=false;
            }
            if(s[2]==-1){
                if(!(s[0]==r-2&&s[1]==r-1)){
                    g=false;
                }
            }
        }
        if(s[1]==r-2||s[1]==r-1){
            if(s[2]==1){
                if(ins(s[0],l,r)) g=false;
            }
            if(s[2]==0){
                if(ins(s[0],l,r-2)) g=false;
            }
            if(s[2]==-1){
                if(!(s[0]==r-2&&s[1]==r-1)){
                    g=false;
                }
            }
        }
    }
    if(g) 
        d[l][r]+=dp(l,r-2);
    return d[l][r];
}

bool check(char c){
    return c=='='||c=='<'||c=='>';
}

string sym(){
    char c;
    string s;
    while(!check(c=getchar()));
    s.pb(c);
    if(check(c=getchar())) s.pb(c);
    return s;
}

vector<int> get(){
    int a,b,t;
    string s;
    scanf("%d",&a);
    s=sym();
    scanf("%d",&b);
    a--;
    b--;
    if(s[0]=='>'||s[0]=='='&&a>b){
        t=a;
        a=b;
        b=t;
    }
    vector<int> ans;
    ans.pb(a);
    ans.pb(b);
    ans.pb(2-s.size());
    if(s[0]=='='){
        ans[2]=-1;
        if(a==b) ans[2]=-2;
    }
    else{
        if(a==b&&s.size()==1){
            ans[2]=2;
        }
    }
    return ans;
}

void solve(int n){
   int m,c=1;
   scanf("%d",&m);
   For(i,m){
       sn.pb(get());
       if(sn.back()[2]==-2) sn.pop_back();
       if(sn.back()[2]==2) c=0;
   }
   For(i,80){
       For(j,80){
           d[i][j]=-1;
       }
   }
   printf("%I64d",dp(0,2*n)*c);





}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    char c[5555];
    int n;
    while(scanf("%d",&n)==1) solve(n);
    


    return 0;
}