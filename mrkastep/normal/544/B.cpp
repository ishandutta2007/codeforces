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

void solve(int n){
    int k;
    scanf("%d",&k);
    if(k>(n*n+1)/2){
        printf("NO");
        return;
    }
    printf("YES\n");
    For(i,n){
        For(j,n){
            if((i+j)%2==0){
                if(k>0){
                    printf("L");
                    k--;
                }
                else{
                    printf("S");
                }
            }
            else{
                printf("S");
            }
        }
        printf("\n");
    }

}




char c[1001000];

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