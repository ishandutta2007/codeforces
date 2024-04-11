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
int T,n,b[260],bl;
string st;

signed main()
{
    T=read();
    while (T--)
    {
    	n=read();memset(b,0,sizeof(b));
    	for (int i=1;i<=n;i++)
    	{
    		cin>>st;
    		for (int j=0;j<st.length();j++)
    		  b[st[j]-'a']++;
    	}
    	bl=1;
    	for (int i=0;i<=25;i++)
    	  if (b[i]%n!=0) bl=0;
    	if (bl) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
}