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

string st;
int a[705],f[705][705][10][2],mo=1000000007,n,ans=0; 

signed main()
{
    cin>>st;
    n=st.length();
    for (int i=1;i<=n;i++) a[i]=st[i-1]-48;
    for (int i=0;i<=9;i++) f[0][0][i][0]=1;
    for (int i=1;i<=n;++i)
		for (int j=0;j<i;++j)
			for (int k=1;k<=9;++k)
				for (int l=0;l<=1;++l)
					for (int p=0;p<=(l?9:a[i]);++p)
						(f[i][j+(p>=k)][k][l||(p<a[i])]+=f[i-1][j][k][l])%=mo;
    for (int k=1;k<=9;++k)
        for (int i=1,p=1;i<=n;++i,p=(10ll*p+1)%mo)
            ((ans+=1ll*p*(f[n][i][k][0]+f[n][i][k][1])%mo))%=mo;
    writeln(ans);
}