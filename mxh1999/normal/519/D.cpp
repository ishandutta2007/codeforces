#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 100010
typedef long long ll;
int a[26];
char s[maxn];
int n;
map<pair<int,ll>,int>   M;
ll sum,ans;

int main()
{
    for (int i=0;i<26;i++)  scanf("%d",&a[i]);
    scanf("%s",s+1);
    n=strlen(s+1);
    sum=0;
    for (int i=1;i<=n;i++)
    {
        ans+=M[make_pair(s[i]-'a',sum)];
        sum+=a[s[i]-'a'];
        M[make_pair(s[i]-'a',sum)]++;
    }
    printf("%I64d\n",ans);
    return 0;
}