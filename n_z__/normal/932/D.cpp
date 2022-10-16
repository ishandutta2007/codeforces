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
    #define int double
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
using namespace std;
int f[400001][21],h[400001],a[400001],w[400001];
signed main()
{
	int T,t=1,lastans=0;
	cin>>T;
	h[0]=-1;
	int x,y,z;
	while(T--)
	{
		cin>>x>>y>>z;
		y^=lastans,z^=lastans;
		if(x==1){
			if(a[y]<z){
				for(int u=19,q=f[y][u];u>=0;u--,q=f[y][u])
				if(q&&a[q]<z)y=q;
				y=f[y][0];
			}
			f[++t][0]=y,a[t]=z,w[t]=w[y]+z,h[t]=h[y]+1;
			for(int u=1;u<=19;u++)f[t][u]=f[f[t][u-1]][u-1];
		}
		else {
			int nw=y;
			for(int u=19,q=f[nw][u];u>=0;u--,q=f[nw][u])
			if(z>=w[y]-w[q])nw=q;
			lastans=h[y]-h[nw],cout<<lastans<<endl;
		}
	}
}