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
int len;
LL num[30], arr[30][30];
char str[100010];
LL ans=0;
int main(){
    scanf("%s", str+1);
    len=strlen(str+1);
    for(int i=1; i<=len; i++){
        for(int j=1; j<=26; j++){
            arr[j][str[i]-'a'+1]+=num[j];
        }
        num[str[i]-'a'+1]++;
    }
    for(int i=1; i<=26; i++){
        ans=max(ans, num[i]);
        for(int j=1; j<=26; j++){
            ans=max(ans, arr[i][j]);
        }
    }
    printf("%lld", ans);
}