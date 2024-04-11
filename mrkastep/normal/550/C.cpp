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
//#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
//const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;





void solve(string &s){
    vector<int> v,a;
    int n=s.size();
    bool zero=false;
    v.pb(0);
    v.pb(0);
    For(i,n){
        v.pb(s[i]-'0');
        if(v[i+2]==0) zero=true;
    }
    if(zero){
        printf("YES\n0");
        return;
    }
    For(i,n+2){
        a.pb(v[i]);
        For(j,i){
            a.pb(v[j]);
            For(k,j){
                a.pb(v[k]);
                if((a[0]+a[1]*10+a[2]*100)%8==0){
                    printf("YES\n");
                    bool ready=false;
                    For(c,3){
                        if(a[2-c]>0||ready){
                            ready=true;
                            printf("%d",a[2-c]);
                        }
                    }
                    return;
                }
                a.pop_back();
            }
            a.pop_back();
        }
        a.pop_back();
    }
    printf("NO");


}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char c[111111];
    string s;
    while(gets(c)){
        solve(s=c);
        printf("\n");
    }






    return 0;
}