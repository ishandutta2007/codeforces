#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
vector<int>V;
void sol(int c1,int c2,int a,int b)
{
    rep(asaw,0,c1)
    {
        int asbw=c1-asaw;
        int bsaw=a-asaw;
        int bsbw=b-asbw;
        if(asbw<0||bsaw<0||bsbw<0)continue;
        V.push_back(asbw+bsaw);
    }
}
int main()
{
    int T=rd();
    while(T--)
    {
        int a,b,c,c1,c2;
        a=rd();b=rd();c=a+b;V.clear();
        c2=c/2;c1=c-c2;sol(c1,c2,a,b);
        if(c1!=c2)sol(c1,c2,b,a);
        sort(V.begin(),V.end());
        V.erase(unique(V.begin(),V.end()),V.end());
        printf("%d\n",(int)V.size());
        fore(i,V)printf("%d ",V[i]);
        puts("");
    }
    return 0;
}