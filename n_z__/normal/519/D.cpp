#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#define MOD 10019
#define Nmax 1000005
#define INF 2000000000
#define VAL 3000000
#define eps 0.000000000001
 
using namespace std;
 
struct el
{
    long long val;
    int cnt;
};
 
vector <el> H[MOD];
 
int n;
int val[1000];
long long s[Nmax];
vector <int> L[1000];
char sir[Nmax];
 
inline int SH(long long x)
{
    int key=abs(x)%MOD;
    vector <el> ::iterator it;
    el w;
 
    for(it=H[key].begin();it!=H[key].end();++it)
        if(it->val==x)
            return it->cnt;
 
    return 0;
}
 
inline void AH(long long x)
{
    int key=abs(x)%MOD;
    vector <el> ::iterator it;
    el w;
 
    for(it=H[key].begin();it!=H[key].end();++it)
        if(it->val==x)
        {
            it->cnt++;
            return;
        }
 
    w.val=x; w.cnt=1;
    H[key].push_back(w);
}
 
int main()
{
    int i,j,len;
    long long sol=0;
    vector <int> ::iterator it;
    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif
    cin.sync_with_stdio(0);
    for(i=0;i<26;++i) cin>>val[i];
    cin>>(sir+1);
    len=strlen(sir+1);
    for(i=1;i<=len;++i)
    {
        L[sir[i]-'a'].push_back(i);
        s[i]=s[i-1]+val[sir[i]-'a'];
    }
    for(i=0;i<26;++i)
    {
        for(j=0;j<MOD;++j) H[j].clear();
        for(it=L[i].begin();it!=L[i].end();++it)
        {
            sol+=SH(s[*it-1]);
            AH(s[*it]);
        }
    }
    cout<<sol;
    return 0;
}