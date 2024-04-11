/*
Codeforces 1495A. Diamond Miner
*/
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
const int N=100005;
int n,a[N],l[N],r[N];
int main()
{
    n=rd();
    rep(i,1,n)a[i]=rd();
    rep(i,1,n)l[i]=(i>1&&a[i-1]<a[i])?l[i-1]+1:1;
    per(i,n,1)r[i]=(i<n&&a[i+1]<a[i])?r[i+1]+1:1;
//    rep(i,1,n)cout<<l[i]<<" ";cout<<endl;
//    rep(i,1,n)cout<<r[i]<<" ";cout<<endl;
    int mx=0,ans=0,sl=0,sr=0;
    rep(i,1,n)mx=max(mx,l[i]);
    rep(i,1,n)mx=max(mx,r[i]);
    rep(i,1,n)if(l[i]==mx)sl++;
    rep(i,1,n)if(r[i]==mx)sr++;
    if(sl>1||sr>1){puts("0");return 0;}
    rep(i,1,n)if(l[i]==mx&&r[i]==mx&&(mx&1))
    {
        puts("1");return 0;
    }
    puts("0");
    return 0;
}