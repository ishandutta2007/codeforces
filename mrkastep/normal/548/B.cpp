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

point p;

bool srt(int a,int b){
    return a>b;
}


void solve(int n){
    int m,q;
    scanf("%d%d",&m,&q);
    int t[505][505];
    map<int,int> mm;
    For(i,n){
        int s=0;
        For(j,m){
            scanf("%d",&t[i][j]);
            s+=t[i][j];
            if(t[i][j]==0){
                mm[s]++;
                s=0;
            }
        }
        mm[s]++;
    }
    int a,b;
    For(i,q){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        int s=0;
        int l=0,r=0;
        while(b-l>=0&&t[a][b-l]==1){
            l++;
        }
        while(b+r<m&&t[a][b+r]==1){
            r++;
        }
        mm[l+r-1]--;
        if(mm[l+r-1]==0) mm.erase(s);
        if(t[a][b]){
            l=0;
            r=0;
            while(b-l>=0&&t[a][b-l]==1){
                l++;
            }
            while(b+r<m&&t[a][b+r]==1){
                r++;
            }
            if(mm[l+r-1]==0) mm.erase(l+r-1);
            mm[l-1]++;
            mm[r-1]++;
            t[a][b]=0;
        }
        else{
            t[a][b]=1;
            l=0;
            r=0;
            while(b-l>=0&&t[a][b-l]==1){
                l++;
            }
            while(b+r<m&&t[a][b+r]==1){
                r++;
            }
            mm[l-1]--;
            mm[r-1]--;
            if(mm[l-1]==0) mm.erase(l-1);
            if(mm[r-1]==0) mm.erase(r-1);
            mm[l+r-1]++;
        }
        mm[s]++;
        printf("%d\n",prev(mm.end())->x);
    }

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char c[111];
    string s;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}