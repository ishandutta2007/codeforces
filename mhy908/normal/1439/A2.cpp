#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int t, n, m, re;
int arr[110][110];
pii a1[100010], a2[100010], a3[100010];
int x[4], y[4];


void solve(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)scanf("%1d", &arr[i][j]);
    }
    re=0;
    for(int i=1; i<=n-2; i++){
        for(int j=1; j<=m; j++){
            if(!arr[i][j])continue;
            if(j!=m){
                a1[++re]=mp(i, j);
                a2[re]=mp(i+1, j);
                a3[re]=mp(i+1, j+1);
                arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
            }
            else{
                a1[++re]=mp(i, j);
                a2[re]=mp(i+1, j);
                a3[re]=mp(i+1, j-1);
                arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
            }
        }
    }
    for(int j=1; j<=m-2; j++){
        if(arr[n-1][j]==1&&arr[n][j]==1){
            a1[++re]=mp(n-1, j);
            a2[re]=mp(n, j);
            a3[re]=mp(n-1, j+1);
            arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
            arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
            arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
        }
        else if(arr[n-1][j]==1){
            a1[++re]=mp(n-1, j);
            a2[re]=mp(n-1, j+1);
            a3[re]=mp(n, j+1);
            arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
            arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
            arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
        }
        else if(arr[n][j]==1){
            a1[++re]=mp(n, j);
            a2[re]=mp(n-1, j+1);
            a3[re]=mp(n, j+1);
            arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
            arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
            arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
        }
    }
    x[0]=x[1]=n-1, x[2]=x[3]=n;
    y[0]=y[3]=m-1, y[1]=y[2]=m;
    int cnt=0;
    for(int i=0; i<4; i++){
        if(arr[x[i]][y[i]])cnt++;
    }
    if(cnt==1){
        for(int i=0; i<4; i++){
            if(arr[x[i]][y[i]]){
                for(int j=0; j<4; j++){
                    if(j%4==(i+2)%4)continue;
                    a1[++re]=mp(x[j], y[j]);
                    a2[re]=mp(x[(j+1)%4], y[(j+1)%4]);
                    a3[re]=mp(x[(j+3)%4], y[(j+3)%4]);
                    arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
                }
            }
        }
    }
    if(cnt==4){
        for(int j=0; j<4; j++){
            a1[++re]=mp(x[j], y[j]);
            a2[re]=mp(x[(j+1)%4], y[(j+1)%4]);
            a3[re]=mp(x[(j+3)%4], y[(j+3)%4]);
            //arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                //arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                //arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
        }
    }
    if(cnt==3){
        for(int j=0; j<4; j++){
            if(arr[x[j]][y[j]]==0){
                a1[++re]=mp(x[(j+2)%4], y[(j+2)%4]);
                a2[re]=mp(x[(j+1)%4], y[(j+1)%4]);
                a3[re]=mp(x[(j+3)%4], y[(j+3)%4]);
                //arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                //arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                //arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
            }
        }
    }
    if(cnt==2){
        if(arr[x[0]][y[0]]==arr[x[2]][y[2]]){
            for(int i=0; i<2; i++){
                if(arr[x[i]][y[i]]){
                    for(int j=0; j<4; j++){
                        if(i!=j%2)continue;
                        a1[++re]=mp(x[j], y[j]);
                        a2[re]=mp(x[(j+1)%4], y[(j+1)%4]);
                        a3[re]=mp(x[(j+3)%4], y[(j+3)%4]);
                        //arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                //arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                //arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
                    }
                }
            }
        }
        else{
            for(int i=0; i<4; i++){
                if(arr[x[i]][y[i]]&&arr[x[(i+1)%4]][y[(i+1)%4]]){
                    for(int j=0; j<4; j++){
                        if(i==j||(i+1)%4==j)continue;
                        a1[++re]=mp(x[j], y[j]);
                        a2[re]=mp(x[(j+1)%4], y[(j+1)%4]);
                        a3[re]=mp(x[(j+3)%4], y[(j+3)%4]);
                        //arr[a1[re].F][a1[re].S]=1-arr[a1[re].F][a1[re].S];
                //arr[a2[re].F][a2[re].S]=1-arr[a2[re].F][a2[re].S];
                //arr[a3[re].F][a3[re].S]=1-arr[a3[re].F][a3[re].S];
                    }
                }
            }
        }
    }
    printf("%d\n", re);
    for(int i=1; i<=re; i++)printf("%d %d %d %d %d %d\n", a1[i].F, a1[i].S, a2[i].F, a2[i].S, a3[i].F, a3[i].S);
    //puts("!");
    //for(int i=1; i<=n; i++){
    //    for(int j=1; j<=m; j++)printf("%d ", arr[i][j]);
    //    puts("");
    //}
}





int main(){
    scanf("%d", &t);
    while(t--)solve();
}