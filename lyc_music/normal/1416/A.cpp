//QwQcOrZ yyds!!!
#include<bits/stdc++.h>

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

int T,n,a[300005],l,r,minn,cnt,s[300005],lst[300005],ans[300005];

signed main()
{
	T=read();
	while (T--)
	{
		n=read();memset(ans,0x3f,sizeof(ans));
		for (int i=1;i<=n;i++) s[i]=0,lst[i]=0;
		for (int i=1;i<=n;i++) 
		{
			a[i]=read();
			s[a[i]]=max(i-lst[a[i]],s[a[i]]);
			lst[a[i]]=i;
		}
		for (int i=1;i<=n;i++) s[i]=max(s[i],n+1-lst[i]);
		for (int i=1;i<=n;i++) 
		  ans[s[i]]=min(ans[s[i]],i);
		for (int i=1;i<=n;i++) 
		  ans[i]=min(ans[i],ans[i-1]);
		for (int i=1;i<=n;i++) 
			if (ans[i]==0x3f3f3f3f) cout<<-1<<" "; else  cout<<ans[i]<<" ";
		cout<<endl;
	}
}