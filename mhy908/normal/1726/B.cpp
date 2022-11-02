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

int n, m;

void solve(){
    scanf("%d %d", &n, &m);
    if(n>m){
        puts("No");
        return;
    }
    if(n==1){
        puts("Yes");
        printf("%d\n", m);
    }
    else if(n==2){
        if(m%2)puts("No");
        else{
            puts("Yes");
            printf("%d %d\n", m/2, m/2);
        }
    }
    else if(n%2){
        puts("Yes");
        for(int i=1; i<=n-1; i++)printf("1 ");
        printf("%d\n", m-n+1);
    }
    else{
        if(m%2){
            puts("No");
        }
        else{
            puts("Yes");
            for(int i=1; i<=n-2; i++)printf("1 ");
            printf("%d %d\n", (m-n+2)/2, (m-n+2)/2);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}