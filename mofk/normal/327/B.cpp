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
int n,a[1440005]={0},i,j;
int main(void)
{
    ff(i,2,1200) if(!a[i]) ff(j,i,1440000/i) a[i*j]=1;
    scanf("%d",&n);int k=0;i=2;
    while(k<n)
    {
        if(!a[i]) {printf("%d ",i);k++;}i++;
    }
}