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

int n, ans;
char str[100010];
void solve(){
    scanf("%s", str+1);
    n=strlen(str+1);
    ans=0;
    if(n<=1){
        printf("0\n");
        for(int i=1; i<=n; i++)str[i]=0;
        return;
    }
    if(n<=2){
        if(str[1]==str[2])printf("1\n");
        else printf("0\n");
        for(int i=1; i<=n; i++)str[i]=0;
        return;
    }
    if(str[1]==str[2]){
        str[2]='X';
        ans++;
    }
    for(int i=3; i<=n; i++){
        if(str[i-1]!='X'&&str[i-1]==str[i]){
            str[i]='X';
            ans++;
        }
        else if(str[i-2]!='X'&&str[i-2]==str[i]){
            str[i]='X';
            ans++;
        }
    }
    printf("%d\n", ans);
    for(int i=1; i<=n; i++)str[i]=0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}