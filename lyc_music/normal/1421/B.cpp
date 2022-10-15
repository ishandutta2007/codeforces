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

int T,n,a,b,c,d;
bool vis[1000][1000]['2'];
char x[1000][1000];
vector<pair<int,int> >ans;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		cin>>x[i]+1;
		int a=x[1][2]-'0',b=x[2][1]-'0',c=x[n][n-1]-'0',d=x[n-1][n]-'0';
		if(a==b&&c==d&&a!=c) writeln(0);
		else if(a!=b&&c!=d)
		cout<<2<<endl<<1<<" "<<2<<endl<<(a==c?n-1:n)<<" "<<(a==c?n:n-1)<<endl;
		else if(a!=b)
		cout<<1<<endl<<(a==c?1:2)<<' '<<(a==c?2:1)<<endl;
		else if(c!=d)
		cout<<1<<endl<<(a==c?n:n-1)<<' '<<(a==c?n-1:n)<<endl;
		else 
		cout<<2<<endl<<1<<' '<<2<<endl<<2<<" "<<1<<endl;
	}
}