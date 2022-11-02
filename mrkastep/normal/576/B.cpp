#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

int a[100100];
bool st[100100];

void solve(int n){
    vector<vector<int>> v;
    For(i,n){
        scanf("%d",&a[i]);
        a[i]--;
        st[i]=true;
    }
    For(i,n){
        if(!st[i]) continue;
        int t=a[i];
        v.pb(vector<int>());
        v.back().pb(i);
        while(t!=i){
            v.back().pb(t);
            st[t]=false;
            t=a[t];
        }
    }
    int mn=INF;
    bool ch=true;
    For(i,v.size()){
        if(v[i].size()%2==1) ch=false;
        mn=min(mn,(int)v[i].size());
    }
    if(mn==1){
        printf("YES\n");
        For(i,v.size()){
            if(v[i].size()==1){
                For(j,n){
                    if(v[i][0]!=j){
                        printf("%d %d\n",v[i][0]+1,j+1);
                    }
                }
                return;
            }
        }
    }
    if(mn==2){
        if(!ch){
            printf("NO");
            return;
        }
        printf("YES\n");
        For(i,v.size()){
            if(v[i].size()==2){
                printf("%d %d\n",v[i][0]+1,v[i][1]+1);
                For(j,v.size()){
                    if(i!=j){
                        For(k,v[j].size()/2){
                            printf("%d %d\n%d %d\n",v[i][0]+1,v[j][2*k]+1,v[i][1]+1,v[j][2*k+1]+1);
                        }
                    }
                }
                return;
            }
        }

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
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}