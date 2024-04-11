#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF= 1LL<<52;
const int MAXN = 2e5+9;

int p[MAXN];//people in poosition (i)*100;
ll rs[MAXN];
int x[MAXN];//ice cream shop

int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        rs[i]=rs[i-1]+p[i];
    }
    for(int i=0;i<m;i++){
        cin >> x[i];
        x[i]+=100;
    }
    sort(x,x+m);
    ll ans = 0;
    ll cans = 0;
    for(int i=1;i<=n&&i*100<x[0];i++){
        cans+=p[i];
    }
    ans = max(ans,cans);
    cans = 0;
    for(int i=n;i&&i*100>x[m-1];i--){
        cans+=p[i];
    }
    ans = max(ans,cans);
    //cout << ans << endl;
    int cj = 0;//what is the first shop pos >=i*100
    for(int i=1;i<=n;i++){
        while(cj<m&&x[cj]<=i*100){
            cj++;
        }
        if(cj==m)break;
        if(cj==0)continue;
        int hl = (x[cj]-x[cj-1]-1)/2;
        //int lp = i*100 - hl;//left most place that we can sell to
        int li = max(x[cj-1]/100+1,i-hl/100);
        ans = max(ans, rs[i]-rs[li-1]);
    }
    cout << ans;
}