#include<bits/stdc++.h>
#define int long long
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
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

long long n,a[1000005],mid,ans=0,sum=0,bl;
long long tot;
signed main()
{
    n=read();ans=(1ll<<62);
    for (int i=1;i<=n;i++)
      a[i]=read(),sum+=a[i];
    sort(a+1,a+n+1);
    int last=INT_MAX;
    for (int mid=1;mid;mid++)
	{ 
	tot=1;sum=0;bl=0;
    for (int i=1;i<=n;i++)
    {
    	if (tot>1000000000000ll) {bl=1;break;}
    	sum+=llabs(a[i]-tot);
    	//cout<<i<<" "<<ans<<" "<<mid<<endl;
    	tot*=mid;
    }//if (mid>1000000)cout<<mid<<endl;
    if (bl) break;
    ans=min(ans,sum);
	}
	writeln(ans);
}