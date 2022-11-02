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
const int N=2025;
int n,a[N];
vector<int>V;
inline void rev(int p)
{
    if(p==1)return;
    assert(p>=1&&p<=n);
    if(p<1||p>n)return;
    reverse(a+1,a+p+1);
    V.push_back(p);
}
int main()
{
    int T=rd();srand(time(0));
    while(T--)
    {
        n=rd();int ff=0;V.clear();
        rep(i,1,n)a[i]=rd();
        rep(i,1,n)if((a[i]+i)&1)ff=1;
        if(ff)
        {
            puts("-1");
            continue;
        }
        for(int i=n;i>=3;i-=2)
        {
            if((a[i]==i)&&(a[i-1]==i-1))continue;
            int p=0;
            for(int j=1;j<=i;j+=2)if(a[j]==i){p=j;break;}
            rev(p);
            int q=0;
            for(int j=2;j<=i;j+=2)if(a[j]==i-1){q=j;break;}
            rev(q-1);rev(q+1);rev(3);rev(i);
        }
        if(!V.size()){V.push_back(n);V.push_back(n);}
        printf("%d\n",(int)V.size());
        fore(i,V)printf("%d ",V[i]);puts("");
    }
    return 0;
}