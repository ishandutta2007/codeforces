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

void solve(string &a){
    string s1,s2;
    int sa[26],sb[26],sc[26];
    char c[100100];
    For(i,26){
        sa[i]=sb[i]=sc[i]=0;
    }
    For(i,a.size()){
        sa[a[i]-'a']++;
    }
    gets(c);
    s1=c;
    int n=strlen(c);
    For(i,n){
        sb[c[i]-'a']++;
    }
    gets(c);
    s2=c;
    int c1,c2,mx=0;
    n=strlen(c);
    For(i,n){
        sc[c[i]-'a']++;
    }
    For(i,a.size()+1){
        int cc=INF;
        bool g=true;
        For(j,26){
            if(sb[j]*i>sa[j]){
                g=false;
                break;
            }
            if(sc[j]!=0) cc=min(cc,(sa[j]-sb[j]*i)/sc[j]);
        }
        if(!g) break;
        if(mx<cc+i){
            c1=i;
            c2=cc;
            mx=cc+i;
        }
    }
    For(i,26){
        sa[i]-=sb[i]*c1+sc[i]*c2;
    }
    For(i,c1){
        printf("%s",s1.c_str());
    }
    For(i,c2){
        printf("%s",s2.c_str());
    }
    For(i,26){
        For(j,sa[i]){
            printf("%c",'a'+i);
        }
    }


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
    while(gets(c)){
        solve(s=c);
        printf("\n");
    }






    return 0;
}