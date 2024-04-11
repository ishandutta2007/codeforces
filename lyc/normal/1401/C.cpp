#include<bits/stdc++.h>
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
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int T,n,mn,cnt,a[N],b[N],c[N];
signed main()
{
    cin>>T;
    while (T--)
    {
    	cin>>n;mn=INT_MAX;cnt=0;
    	for (int i=1;i<=n;i++)
    	{
    		cin>>a[i];
    		mn=min(mn,a[i]);
    	}
    	for (int i=1;i<=n;i++)
    	  if (a[i]%mn==0)
    	  {
    	  	cnt++;
    	  	b[cnt]=a[i];
    	  	c[cnt]=i;
    	  }
    	sort(b+1,b+cnt+1);
    	for (int i=1;i<=cnt;i++) a[c[i]]=b[i];
    	bool bl=0;
    	for (int i=2;i<=n;i++)
    	  if (a[i]<a[i-1])
    	  {
    	  	bl=1;
    	  	break;
    	  }
    	if (!bl) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }		
}