#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=9000000000000000000;
const int inf=2000000000;
int n;
char str[110];
bool ch(char a[]){
    int len=strlen(a+1);
    int num=0, evennum=0;
    bool iszero=false;
    for(int i=1; i<=len; i++){
        if(str[i]=='0')iszero=true;
        if((int)(str[i]-'0')%2==0)evennum++;
        num+=(int)(str[i]-'0');
    }
    if(iszero&&evennum>=2&&num%3==0)return true;
    return false;
}
int main()
{
    scanf("%d", &n);
    for(int u=1; u<=n; u++){
        memset(str, 0, sizeof(str));
        scanf("%s", str+1);
        if(ch(str))puts("red");
        else puts("cyan");
    }
}