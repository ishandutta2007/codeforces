#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;

typedef pair<double,double> point;

int down(ll a){
    ll l=1;
    ll r=a+2;
    while(r-l>1){
        int c=(l+r)/2;
        if((ll)c*(c-1)/2>a){
            r=c;
        }
        else{
            l=c;
        }
    }
    return l;
}


int gcd(ll a,ll b){
    a=abs(a);
    b=abs(b);
    while(a>0&&b>0){
        if(a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return max(a,b);

}



void solve(int n){
    map<vector<ll>,ll> m;
    pair<ll,ll> p;
    vector<pair<ll,ll>> v;
    For(i,n){
        scanf("%I64d%I64d",&p.x,&p.y);
        v.pb(p);
    }
    For(i,n){
        For(j,i){
            vector<ll> t(3);
            if(v[i].x==v[j].x){
                t[0]=1;
                t[1]=0;
                t[2]=v[i].x;
            }
            else{
                t[0]=(v[i].y-v[j].y);
                t[1]=-(v[i].x-v[j].x);
                t[2]=v[i].y*(v[i].x-v[j].x)-(v[i].y-v[j].y)*v[i].x;
            }
            if(t[0]<0){
                t[0]*=-1;
                t[1]*=-1;
                t[2]*=-1;
            }
            else{
                if(t[0]==0&&t[1]<0){
                    t[0]*=-1;
                    t[1]*=-1;
                    t[2]*=-1;
                }
            }

            int tmp=1;
            if(t[2]==0){
                if(t[1]==0){
                    t[0]=1;
                }
                else{
                    if(t[0]==0){
                        t[1]=1;
                    }
                    else{
                        tmp=gcd(t[0],t[1]);
                    }
                }
            }
            else{
                if(t[1]==0){
                    tmp=gcd(t[0],t[2]);
                }
                else{
                    if(t[0]==0){
                        tmp=gcd(t[1],t[2]);
                    }
                    else{
                        tmp=gcd(t[0],gcd(t[1],t[2]));
                    }
                }
            }
            For(k,3){
                t[k]/=tmp;
            }
            m[t]++;
        }
    }
    vector<ll> a;
    for(auto it=m.begin();it!=m.end();it++){
        a.pb(down(it->y));
    }
    ll ans=(ll)n*(n-1)*(n-2)/6;
    For(i,a.size()){
        ans-=(ll)a[i]*(a[i]-1)*(a[i]-2)/6;
    }
    printf("%I64d",ans);








}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}