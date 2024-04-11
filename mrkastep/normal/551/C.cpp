#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ll long long int


const int INF=2e9;
int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

void solve(int n){
    int m,a;
    vector<int> box,tmp;
    scanf("%d",&m);
    For(i,n){
        scanf("%d",&a);
        box.pb(a);
    }
    while(!box.empty()&&box.back()==0){
        box.pop_back();
    }
    ll r=1e18,l=1;
    while(r-l>1){
        ll c=(l+r)/2;
        tmp=box;
        bool g=true;
        For(i,m){
            if(c<tmp.size()){
                g=false;
                break;
            }
            ll t=c;
            t-=tmp.size();
            while(!tmp.empty()){
                while(t>0&&tmp.size()>0){
                    if(!tmp.empty()){
                        if(tmp.back()>t){
                            tmp.back()-=t;
                            t=0;
                        }
                        else{
                            t-=tmp.back();
                            tmp.back()=0;
                        }
                    }
                    while(!tmp.empty()&&tmp.back()==0){
                        tmp.pop_back();
                    }
                }
                if(t==0) break;
            }
        }
        if(tmp.size()>0) g=false;
        if(g){
            r=c;
        }
        else{
            l=c;
        }
    }
    printf("%I64d",r);
}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    char c[100100];
    ll a;
    while(scanf("%d",&n)==1){
        solve(n);
        printf("\n");
    }






    return 0;
}