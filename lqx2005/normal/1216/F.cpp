#include <bits/stdc++.h>
using namespace std;
const int maxn=5000000;
struct Queue
{
	int q[maxn+5];
	int l,r;
	Queue(){l=1,r=0;}
	void Pushback(int v){q[++r]=v;}
	void Popfront(){l++;}
	void Clear(){l=1,r=0;}
	bool Empty(){return l==r+1;}
	int Front(){return q[l];}
}q;
int n,k;
int t,fnd[maxn+5];
long long f[maxn+5];
char ice[maxn+5];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",ice+1);   
    fnd[n+1]=n*5;
    for(int i=n;i>=1;i--) 
	{
		if(ice[i]=='1') fnd[i]=i;
		else fnd[i]=fnd[i+1];
	} 
	fnd[0]=fnd[1];
    for(register int i=0;i<=n;i++) f[i]=0;
    for(register int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+i;
        int pos=i-k;
        pos=max(pos,0);
        pos=fnd[pos];
        if(pos>i+k) continue;
        f[i]=min(f[i],1ll*f[max(1,pos-k)-1]+1ll*pos);
    }
    printf("%lld\n",f[n]);
    return 0;
}