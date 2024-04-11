//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long 
#define N 100005
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){ 
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

string st;
int n,f[N],ans,tmp,sum[N],mod=1e9+7;

signed main()
{
	cin>>st;
	st=' '+st;
	n=st.length()-1;
	f[1]=1;
	for (int i=2;i<=n;i++) f[i]=(f[i-1]*10)%mod;
	for (int i=1;i<=n;i++) (sum[i]=sum[i-1]+f[i])%=mod;
	tmp=0;
	for (int i=n;i>=1;i--)
	{
		(ans+=tmp*(int)(st[i]-'0')%mod)%=mod;
		(ans+=(i*(i-1))/2%mod*(int)(st[i]-'0')*f[n-i+1]%mod)%=mod;
		(tmp+=f[n-i+1]*(n-i+1)%mod)%=mod;
		//((ans-=f[n-i+1]*(int)(st[i]-'0')%mod)+=mod)%=mod;
		//writeln(ans);
	}
	writeln(ans);
}