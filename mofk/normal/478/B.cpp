#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstring>
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define F(i,n) for (i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define fi first
#define se second
#define B 1
#define W -1
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int MAX=100005; const ll mod=666013;

ll n,m,a1,a2,a3;

ll c(ll n)
{
    return n*(n-1)/2;
}

int main(void)
{
    scanf("%I64d%I64d",&n,&m);
    ll k=n/m;ll r=n%m;
    a1=r*c(k+1)+(m-r)*c(k);
    a2=c(n-m+1);
    printf("%I64d %I64d",a1,a2);
}