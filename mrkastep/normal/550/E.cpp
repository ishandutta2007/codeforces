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
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

vector<int> v;
int p=INF;

string s="";

void solve(int n){
    int a;
    if(v.back()!=0){
        printf("NO");
        return;
    }
    if(v.size()==2){
        if(v[0]==0){
            printf("NO");
        }
        else{
            printf("YES\n");
            printf("1->0");
        }
        return;
    }
    if(v[n-3]==1&&v[n-2]==0){
        if(s==""){
            for(int i=n-3;i>=0&&v[i]==1;i--){
                p=i;
            }
            FOR(i,p,n-2){
                s+="(1->";
            }
            s+="0";
            FOR(i,p,n-2) s+=')';
        }
        v.pop_back();
        v.pop_back();
        v.pop_back();
        For(i,2) v.pb(0);
        solve(n-1);
        return;
    }
    printf("YES\n");
    if(v[n-2]==1){
        For(i,n-1){
            printf("%d->",v[i]);
        }
        printf("0");
        return;
    }
    For(i,n-1){
        if(i==n-3){
            printf("(");
        }
        if(i!=p) printf("%d",v[i]);
        else printf("%s",s.c_str());
        if(i==n-2){
            printf(")");
        }
        printf("->");
    }
    printf("0");





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
    while(scanf("%d",&n)==1){
        int a;
        For(i,n){
            scanf("%d",&a);
            v.pb(a);
        }
        solve(n);
        printf("\n");
    }






    return 0;
}