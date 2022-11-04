#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e6+10;
const int maxint = 0x3f3f3f3f;
const LL mod = 1e9+7;

#define mst(a,b) memset((a),(b),sizeof(a))  
#define rush() int T;scanf("%d",&T);while(T--)  

LL fac[maxn];  
LL inv[maxn];  
  
LL fast_mod(LL a,LL n,LL Mod)  
{  
    LL ans=1;  
    a%=Mod;  
    while(n)  
    {  
        if(n&1) ans=(ans*a)%Mod;  
        a=(a*a)%Mod;  
        n>>=1;  
    }  
    return ans;  
}  
  
void init()  
{  
    fac[0]=1;  
    for(int i=1;i<maxn;i++)  
    {  
        fac[i]=(fac[i-1]*i)%mod;  
    }  
    inv[maxn-1]=fast_mod(fac[maxn-1],mod-2,mod);  
    for(int i=maxn-2;i>=0;i--)  
    {  
        inv[i]=(inv[i+1]*(i+1))%mod;  
    }  
}  
  
LL C(int n,int m)  
{  
    return fac[n]*inv[m]%mod*inv[n-m]%mod;  
}  
  
int main()  
{  
    init();  
    rush()  
    {  
        int x,y;  
        scanf("%d%d",&x,&y);  
        vector<int>vec;  
        for(int i=2;i*i<=x;i++)     //  
        {  
            if(x%i==0)  
            {  
                int cnt=0;  
                while(x%i==0)  
                {  
                    cnt++;  
                    x/=i;  
                }  
                vec.push_back(cnt);  
            }  
        }  
        if(x>1) vec.push_back(1);  
        LL ans=1;  
        y--;  
        for(int i=0;i<vec.size();i++)  
        {  
            ans*=C(vec[i]+y,y);                 //  
            ans%=mod;  
        }  
        ans=(ans*fast_mod(2,y,mod))%mod;        //  
        printf("%I64d\n",ans);  
    }  
}