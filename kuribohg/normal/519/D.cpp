#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=100010;
map<pair<LL,char>,int> M;
int w[MAXN],n;
char str[MAXN];
LL s[MAXN],ans;
int main()
{
    for(int i='a';i<='z';i++) scanf("%d",&w[i]);
    scanf("%s",str);
    n=strlen(str);
    s[0]=w[str[0]];
    for(int i=1;i<n;i++) s[i]=s[i-1]+w[str[i]];
    for(int i=1;i<n;i++)
    {
        if(!M.count(make_pair(s[i-1],str[i]))) M[make_pair(s[i-1],str[i])]=1;
        else M[make_pair(s[i-1],str[i])]++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(M.count(make_pair(s[i],str[i]))) ans+=M[make_pair(s[i],str[i])];
        M[make_pair(s[i],str[i+1])]--;
    }
    printf("%I64d\n",ans);
    return 0;
}