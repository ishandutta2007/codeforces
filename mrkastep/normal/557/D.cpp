#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

//#define For(i,n) for(int i=0;i<(n);i++)
//#define FOR(i,a,b) for(int i=(a);i<(b);i++)
//#define pb push_back
//#define mp make_pair
//#define x first
//#define y second
//#define ll long long int
//#define all(v) (v).begin(),(v).end()
//
//const int INF=2e9;
//const int mod=1e9+7;
//const ll LONGINF=4e18;
//const double eps=1e-9;
//const double PI=3.1415926535897932384626433832795;
//
//typedef pair<double,double> point;
long long int n,m,p[1000007],t[1000007],v[1000007][2],ans=0;

long long int find(long long int i){
    long long int pr;
    if(p[i]==i){
        return i;
    }
    pr=find(p[i]);
    t[i]^=t[p[i]];
    p[i]=pr;
    return p[i];
}

long long int add(long long int v1,long long int v2,long long int type){
    long long int p1,p2,x;
    p1=find(v1);
    p2=find(v2);
    if(p1==p2){
        if(((t[v1]^t[v2])^type)==0){
            return 1;
        }else{
            return -1;
        }
    }else{
        x=(t[v1]^t[v2])^type;
        t[p1]=x;
        p[p1]=p2;
        if(t[p1]==0){
            v[p2][0]+=v[p1][0];
            v[p2][1]+=v[p1][1];
        }else{
            v[p2][1]+=v[p1][0];
            v[p2][0]+=v[p1][1];
        }

        return 1;
    }
}

void solve(){
    long long int i,j,x,y,k=0,ty=0;
    for(i=0;i<n;i++){
        p[i]=i;
        v[i][0]=1;
        v[i][1]=0;
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x-=1;
        y-=1;
        if(add(x,y,1)==-1){
            printf("0 1\n");
            return;
        }
    }
    for(i=0;i<n;i++){
        if(p[i]==i){
            if(v[i][0]+v[i][1]>=3){
                ty=2;
            }else{
                if(v[i][0]+v[i][1]>=2){
                    ty=max(ty,(long long int)1);
                    k++;
                }
            }
        }
    }
    if(ty==0){
        ans=(n*(n-1)*(n-2))/6;
        printf("3 %I64d\n",ans);
        return;
    }
    if(ty==1){
        ans=k*(n-2);
        printf("2 %I64d\n",ans);
        return;
    }
    for(i=0;i<n;i++){
        if(p[i]==i){
        ans+=(v[i][0]*(v[i][0]-1))/2;
        ans+=(v[i][1]*(v[i][1]-1))/2;
        }
    }
    printf("1 %I64d\n",ans);
}




int main(){
#pragma comment(linker,"/STACK:268435456")
    char c[5555];
    scanf("%d",&n);
    solve();
    return 0;
}