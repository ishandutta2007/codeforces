#include <iostream>

using namespace std;
//ifstream cin ("plangaciosi.in");
//ofstream cout ("plangaciosi.out");
long long dp[1<<24];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long k,n,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n;
    long long rz=0;
    for(i=1;i<=n;++i)
    {
        s=0;
        char c;
        cin>>c;
        s|=(1<<(c-'a'));
        cin>>c;
        s|=(1<<(c-'a'));
        cin>>c;
        s|=(1<<(c-'a'));
        ++dp[s];
    }
    for(i=0;i<24;++i)
        for(int mask=(1<<i);mask<(1<<24);mask=(mask+1)|(1<<i))
            dp[mask]+=dp[mask^(1<<i)];
    for(i=0;i<(1<<24);++i)
    {
        dp[i]=n-dp[i];
        rz=rz^(dp[i]*1LL*dp[i]);
    }
    cout<<rz;
    return 0;
}