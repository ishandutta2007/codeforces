#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
const int N=5000005,P=1000000007;
int n,m,seed,base,t[N];ll a[N],ans[N];
inline int rnd()
{
    int ret=seed;
    seed=(1ll*seed*base+233)%P;
    return ret;
}
inline void init()
{
    seed=0;base=0;
    int lst=0;
    rep(i,1,m)
    {
        int p=rd(),k=rd();
        seed=rd();base=rd();
        rep(j,lst+1,p)
        {
            t[j]=(rnd()%2)+1;
            a[j]=(rnd()%k)+1;
        }
        lst=p;
    }
}
int main()
{
    n=rd();m=rd();
    init();
    ll s1=0,s2=0;
    rep(i,1,n)if(t[i]==1)s1+=a[i];else s2+=a[i];
    if(s1==s2)
    {
        rep(i,1,n)ans[i]=a[i];
        int res=1;
//        rep(i,1,n)cout<<ans[i]<<" ";cout<<endl;
        rep(i,1,n)res=1ll*((ans[i]^(1ll*i*i))+1)%P*res%P;
        printf("%d\n",res);
        return 0;
    }
    if(s2>s1)
    {
        swap(s1,s2);
        rep(i,1,n)t[i]^=3;
    }
//    rep(i,1,n)cout<<a[i]<<" ";cout<<endl;
//    rep(i,1,n)cout<<t[i]<<" ";cout<<endl;
    if(t[1]!=2){a[1]--;ans[1]++;}
    rep(i,1,n)if(t[i]==2)ans[i]=a[i];
    ll s=0;
    rep(i,1,n)
    {
        if(t[i]==2)s+=a[i];
        else
        {
            ll x=min(s,a[i]);
            a[i]-=x;ans[i]+=x;s-=x;
        }
    }
    rep(i,1,n)
    {
        if(t[i]==1)
        {
            int x=min(s,a[i]);
            a[i]-=x;ans[i]+=x;s-=x;
        }
    }
    int res=1;
 //   rep(i,1,n)cout<<ans[i]<<" ";cout<<endl;
    rep(i,1,n)
    {
        res=1ll*((ans[i]^(1ll*i*i))+1)%P*res%P;
//        cout<<res<<endl;
    }
    printf("%d\n",res);
    return 0;
}