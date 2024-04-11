#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int p[4100][102];

int main(){
    ll n,m,q;
    cin >> n >> m >> q;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        scanf("%d ",&a[i]);
    }
    vector<int>v(1<<n);
    for(int i=0;i<m;i++){
        int x=0;
        for(int j=0;j<n;j++){
            char s;
            scanf("%c ",&s);
            x *=2;
            x += s-'0';
        }
        v[x]++;
    }
    vector<int>ss(1<<n);
    for(int i=0;i<(1<<n);i++){
        int s = 0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                s += a[n-1-j];
            }
        }
        ss[i] = s;
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            int mm = (i^j);
            mm ^= (1<<n)-1;
            int s = ss[mm];
            if(s<=100){
                p[i][s]+=v[j];
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=100;j++){
            p[i][j] += p[i][j-1];
        }
    }
    rep(tt,q){
        int x=0;
        for(int j=0;j<n;j++){
            char s;
            scanf("%c",&s);
            x *=2;
            x += s-'0';
        }
        int t;
        if(tt!=q-1)scanf("%d ",&t);
        if(tt==q-1)scanf("%d",&t);
        printf("%d\n",p[x][t]);
    }
    return 0;
}