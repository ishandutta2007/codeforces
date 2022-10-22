#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 100010
using namespace std;
int ntp[MAXN],p[MAXN],cnt;
void mem()
{
    for(int i=2;i<MAXN-9;i++)
    {
        if(!ntp[i]) p[++cnt]=i;
        for(int j=1;p[j]*i<MAXN-9;j++)
        {
            ntp[p[j]*i]=1;
            if(i%p[j]==0) break;
        }
    }
}
int main()
{
    mem();int ans=0;ll n,y;
    cin>>n;y=n;
    for (ll i=2;i*i<=y;i++) if (!ntp[i])
    {
    	if (n%i==0) {cout<<(n-i)/2+1;return 0;}
	}
	cout<<1;
}