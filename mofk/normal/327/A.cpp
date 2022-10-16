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

int main(void)
{
    int i,j,a[105],n,anss=0,k,ans=0,tmp;
    scanf("%d",&n);
    f(i,n)
    {
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    f(i,n) f(j,i) {tmp=ans;ff(k,j,i) {if(a[k]==1) tmp--;else tmp++;}anss=max(tmp,anss);}
    printf("%d",anss);
}