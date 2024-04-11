#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;

int n, sum[1000010], ans;
char str[1000010];
int main(){
    scanf("%d", &n);
    scanf("%s", str+1);
    for(int i=1; i<=n; i++){
        if(str[i]=='(')sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
    }
    if(sum[n]){
        puts("-1");
        return 0;
    }
    int pv=0;
    for(int i=1; i<=n; i++){
        if(sum[i]<0&&!pv)pv=i;
        if(sum[i]>=0&&pv){
            ans+=i-pv+1;
            pv=0;
        }
    }
    printf("%d", ans);
}