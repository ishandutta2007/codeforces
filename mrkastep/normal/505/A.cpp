#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <time.h>
  
using namespace std;
  
#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
  
const int INF=2e9;
const ll LONGINF=4e18;
const double eps=1e-9;
  
bool check(string s){
    int i;
    For(i,s.length()){
        if(s[i]!=s[s.length()-i-1]) return false;
    }
    return true;
}





void solve(string s){
    vector<string> v;
    string s1;
    int i,j,b;
    For(i,s.length()+1){
        For(b,26){
            s1="";
            For(j,i){
                s1.pb(s[j]);
            }
            s1.pb('a'+b);
            for(;j<s.length();j++){
                s1.pb(s[j]);
            }
            if(check(s1)){
                printf("%s",s1.c_str());
                return;
            }
        }
    }
    printf("NA");
    return;






    
  
#ifdef HOME
    printf("\n\nTime in ms: %.0lf",clock()*1000/CLOCKS_PER_SEC);
#endif
  
  
}
  
  
int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char s[20];
    string c;
    while(gets(s)) solve((c=s));
  
    return 0;
}