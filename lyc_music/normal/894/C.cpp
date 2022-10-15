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

int M,_gcd,a[100005],bl;
vector<int>ans;

int gcd(int x,int y) {return (y==0)?x:gcd(y,x%y);}

signed main()
{
	M=read();
	for (int i=1;i<=M;i++) a[i]=read(),_gcd=gcd(a[i],_gcd);
	for (int i=1;i<=M;i++) a[i]/=_gcd;
	for (int i=1;i<=M;i++) bl|=a[i]==1;
	if (!bl) return writeln(-1),0;
	for (int i=1;i<=M;i++) ans.push_back(_gcd),ans.push_back(a[i]*_gcd);
	writeln(ans.size());
	for (int i=0;i<ans.size();i++) writesp(ans[i]);
}