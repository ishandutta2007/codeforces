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
int n,a[1000005];
int gcd(int x,int y)
{
	if (y==0) return x; else return gcd(y,x%y);
}
signed main()
{
    n=read();
	for (int i=1;i<=n;i++) a[i]=read();
    cout<<"1 1"<<endl;
    cout<<-a[1]<<endl;
	a[1]=0;
	if (n>1)
	{
    cout<<"2 "<<n<<endl;
    for (int i=2;i<=n;i++)
    {
    	cout<<(n-1)*(a[i])<<" ";
    }cout<<endl;
    cout<<"1 "<<n<<endl;
    for (int i=1;i<=n;i++) cout<<-a[i]*n<<" ";}
    else
    {
    	cout<<"1 1"<<endl;
    cout<<-a[1]<<endl;
	a[1]=0;cout<<"1 1"<<endl;
    cout<<-a[1]<<endl;
	a[1]=0;}
}