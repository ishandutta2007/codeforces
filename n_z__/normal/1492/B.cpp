#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
struct IO_Tp {
    const static int _I_Buffer_Size = 2 << 23;
    char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;

    const static int _O_Buffer_Size = 2 << 23;
    char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

    IO_Tp() { fread(_I_Buffer, 1, _I_Buffer_Size, stdin); }
    ~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }
    IO_Tp &operator>>(int &res) {
        int f=1;
        while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        return *this;
    }
    IO_Tp &operator<<(int n) {
        if(n<0)*_O_pos++='-',n=-n;
        static char _buf[10];
        char *_pos = _buf;
        do
            *_pos++ = '0' + n % 10;
        while (n /= 10);
        while (_pos != _buf) *_O_pos++ = *--_pos;
        return *this;
    }
    #define int long long
    IO_Tp &operator>>(int &res) {
        int f=1;
        while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        return *this;
    }
    IO_Tp &operator<<(int n) {
        if(n<0)*_O_pos++='-',n=-n;
        static char _buf[10];
        char *_pos = _buf;
        do
            *_pos++ = '0' + n % 10;
        while (n /= 10);
        while (_pos != _buf) *_O_pos++ = *--_pos;
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
#define int long long 
using namespace std;
int a[100001],b[100001];
void solve(int r,int nowmax){
	if(r==0||nowmax==0)return;
	for(int x=b[nowmax];x<=r;x++)
	cout<<a[x]<<' ';
	r=b[nowmax]-1;
	while(b[--nowmax]>r&&nowmax!=0);
	solve(r,nowmax);
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		cin>>n;
		for(int x=1;x<=n;x++)
		cin>>a[x],b[a[x]]=x;
		solve(n,n);
		cout<<endl;
	}
}