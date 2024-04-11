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

int n;
char str[200010];

char ans1[200010], ans2[200010];

void solve(){
    scanf("%d", &n);
    scanf("%s", str+1);

    int lv1=0, lv2=0, cnt=0, cnt2=0;

    for(int i=1; i<=n; i++){
        if(str[i]=='1')cnt++;
    }

    if(cnt%2){
        for(int j=1; j<=n; j++)str[j]=ans1[j]=ans2[j]=0;
        puts("NO");
        return;
    }

    for(int i=1; i<=n; i++){
        if(str[i]=='0'){
            if(lv1<=lv2){
                ans1[i]='(';
                ans2[i]=')';
                lv1++;
                lv2--;
            }
            else{
                ans2[i]='(';
                ans1[i]=')';
                lv2++;
                lv1--;
            }
        }
        else{
            cnt2++;
            if(cnt2>cnt/2){
                ans1[i]=')';
                ans2[i]=')';
                lv1--;
                lv2--;
            }
            else{
                ans1[i]='(';
                ans2[i]='(';
                lv1++;
                lv2++;
            }
        }
        if(lv1<0||lv2<0||lv1>n-i||lv2>n-i){
            for(int j=1; j<=n; j++)str[j]=ans1[j]=ans2[j]=0;
            puts("NO");
            return;
        }
    }
    puts("YES");
    printf("%s\n%s\n", ans1+1, ans2+1);
    for(int j=1; j<=n; j++)str[j]=ans1[j]=ans2[j]=0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}