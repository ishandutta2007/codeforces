# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
bool c[30]; char a[120000];
int n,cnt,tot;
long long ans = 1;
int main()
{
    scanf("%s",a); n=strlen(a);
    rep(i,n) if(isalpha(a[i])) c[a[i]-'A']=true;
    rep(i,26)if(c[i]) tot++;
    rep(i,n) if(a[i]=='?') cnt++;

    if(tot>10){ puts("0"); return 0; }

    int k = 10;
    if(isalpha(a[0])) ans = 9, tot--, k--;
    if(a[0]=='?') ans = 9, cnt--;
    while(tot--) ans *= k, k--;
    cout << ans;
    while(cnt--) printf("0");
    return 0;
}