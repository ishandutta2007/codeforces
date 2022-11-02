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


void solve(int n){
    vector<int> t(10,0),ans(10,0);
    int i,j,k;
    getchar();
    For(i,n){
        k=getchar()-'0';
        if(k==2){
            t[2]++;
        }
        if(k==3){
            t[2]++;
            t[3]++;
        }
        if(k==4){
            t[2]+=3;
            t[3]++;
        }
        if(k==5){
            t[2]+=3;
            t[3]++;
            t[5]++;
        }
        if(k==6){
            t[2]+=4;
            t[3]+=2;
            t[5]++;
        }
        if(k==7){
            t[2]+=4;
            t[3]+=2;
            t[5]++;
            t[7]++;
        }
        if(k==8){
            t[2]+=7;
            t[3]+=2;
            t[5]++;
            t[7]++;
        }
        if(k==9){
            t[2]+=7;
            t[3]+=4;
            t[5]++;
            t[7]++;
        }
    }
    for(i=7;i>1;i--){
        k=i;
        if(k==6){
            continue;
        }
        if(k==4){
            continue;
        }
        while(t[k]>0){
            printf("%d",k);
            if(k==2){
                t[2]--;
            }
            if(k==3){
                t[2]--;
                t[3]--;
            }
            if(k==5){
                t[2]-=3;
                t[3]--;
                t[5]--;
            }
            if(k==7){
                t[2]-=4;
                t[3]-=2;
                t[5]--;
                t[7]--;
            }
        }
    }




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