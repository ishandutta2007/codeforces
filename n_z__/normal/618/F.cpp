#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
struct IO_Tp {
	#define workread IO_Tp &operator>>(int &res) {int f=1;while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;if(*_I_pos=='-')f=-1,++_I_pos;res = *_I_pos++ - '0';while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');res*=f;return *this;} 
    #define workwrite IO_Tp &operator<<(int n) {if(n<0)*_O_pos++='-',n=-n;static char _buf[10];char *_pos = _buf;do*_pos++ = '0' + n % 10;while (n /= 10);while (_pos != _buf) *_O_pos++ = *--_pos;return *this;}
	const static int _I_Buffer_Size = 2 << 23;char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;const static int _O_Buffer_Size = 2 << 23;char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;IO_Tp() { fread(_I_Buffer, 1, _I_Buffer_Size, stdin); }~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }
    workread
    workwrite
    #define int long long
    workread
    workwrite
    #undef int
    #define int double
    workread
    IO_Tp &operator<<(int n) {
        std::cout<<n;
        return *this;
    }
    #undef int
    IO_Tp &operator<<(char ch) {
        *_O_pos++ = ch;
        return *this;
    }
} IO;
#define cin IO
#define cout IO
#define endl '\n'
using namespace std;
#define int long long
int a[2000001],b[2000001],c[2][1000001],d[2];
main()
{
	int n;
    cin>>n;
    for(int x=1;x<=n*2;x++)
    cin>>a[x],a[x]*=(x<=n)*2-1;
    for(int x=1,e=0;b[x]<=1;b[x]++,x+=a[x],e=x>n)
	if(b[x])d[e]++,c[e][d[e]]=(x-1)%n+1;
    cout<<d[0]<<endl;
    for(int x=1;x<=d[0];x++)
    cout<<c[0][x]<<' ';
    cout<<endl<<d[1]<<endl;
    for(int x=1;x<=d[1];x++)
    cout<<c[1][x]<<' ';
}