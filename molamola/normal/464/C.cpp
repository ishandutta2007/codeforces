#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

const ll MOD = 1e9 +7;
ll pow10(ll x){
    ll res = 1, xx = 10;
    while(x){
        if(x&1)res = res * xx;res %= MOD;
        xx *= xx;xx%=MOD;
        x>>=1;
    }
    return res;
}

vector <int> v[100010];
int dig[100010];
char ch[100010];
int ini[100010];
ll d[100010][10];
ll D[100010][10];

int main()
{
    scanf("%s",ch+1);
    int i;
    int n = strlen(ch+1);
    for(i=1;i<=n;++i)ini[i] = ch[i] - '0';
    int q;
    scanf("%d",&q);
    char ch2[100010];
    for(i=1;i<=q;i++){
        scanf("%s",ch2);
        dig[i] = ch2[0] - '0';
        ch[0] = 0;
        for(int j=3;ch2[j];++j)ch[j-3] = ch2[j], ch[j-2] = 0;
        for(int j=0;ch[j];j++){
            v[i].push_back(ch[j]-'0');
        }
    }
    for(i=0;i<10;i++)d[q][i] = 1;
    for(i=q;i;i--){
        int j=0;
        for(j=0;j<(int)v[i].size();j++){
            d[i-1][dig[i]] += d[i][v[i][j]];
            d[i-1][dig[i]] %= (MOD-1);
        }
        for(j=0;j<10;j++){
            if(j != dig[i])d[i-1][j] = d[i][j];
        }
    }
    ll now_digit = 0;
    for(i=n;i;i--){
        D[0][ini[i]] += pow10(now_digit);
        D[0][ini[i]] %= MOD;
        now_digit += d[0][ini[i]];
        now_digit %= (MOD-1);
    }
//  for(i=0;i<10;i++)printf("%lld\n",D[i]);
    for(i=1;i<=q;i++){
        int j, now = 0;
        for(j=(int)v[i].size()-1;j>=0;j--){
            D[i][v[i][j]] += pow10(now) * D[i-1][dig[i]];
            D[i][v[i][j]] %= MOD;
            now += d[i][v[i][j]];
            now %= (MOD-1);
        }
        for(j=0;j<10;j++){
            if(j != dig[i])D[i][j] += D[i-1][j], D[i][j] %= MOD;
        }
    }
    ll ans = 0;
    for(i=0;i<10;i++){
        ans += D[q][i] * i;
        ans %= MOD;
    }
    printf("%lld",ans);
    return 0;
}