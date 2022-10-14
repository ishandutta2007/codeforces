//Author:MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int T;
const int wx=1e7+10;
int isprime[wx],sd[wx],num[wx],prime[wx];
int tot;
int qwq[wx];
void Euler(){
	memset(isprime,1,sizeof isprime); sd[1]=1;
	for(int i=2;i<=n;i++){
		if(isprime[i]){
			prime[++tot]=i;
			sd[i]=1+i; num[i]=1+i;
		}
		for(int j=1;j<=tot&&prime[j]*i<=n;j++){
			isprime[i*prime[j]]=0;
			if(i%prime[j]!=0){
				sd[i*prime[j]]=sd[i]*sd[prime[j]];
				num[i*prime[j]]=prime[j]+1;
			}
			else{
				sd[i*prime[j]]=sd[i]/num[i]*(num[i]*prime[j]+1);
				num[i*prime[j]]=num[i]*prime[j]+1; break;
			}
		}
	}
}
signed main()
{
	n=1e7;
	Euler();
	memset(qwq,-1,sizeof(qwq));
	up(i,1,10000000)
	{
		if(sd[i]>10000000)continue;
		else
		{
			if(qwq[sd[i]]==-1)qwq[sd[i]]=i;
		}
	}
	int T=read();
	while(T--)
	{
		int x=read();
		cout<<qwq[x]<<endl;
	}
}