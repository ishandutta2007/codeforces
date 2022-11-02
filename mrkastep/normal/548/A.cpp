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

void solve(string &s){
    int k,n=s.size();
    scanf("%d",&k);
    char c[10];
    gets(c);
    if(n%k!=0){
        printf("NO");
        return;
    }
    n/=k;
    For(i,k){
        For(j,n/2){
            if(s[i*n+j]!=s[(i+1)*n-j-1]){
                printf("NO");
                return;
            }
        }
    }
    printf("YES");




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
    }






    return 0;
}