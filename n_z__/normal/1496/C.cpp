#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
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
int a[500001],b[500001];
int main()
{
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		cin>>n;
		int cx=0,cy=0;
		for(int x=1;x<=n*2;x++){
			int y,z;
			cin>>y>>z;
			if(y==0)a[++cx]=abs(z);
			else b[++cy]=abs(y);
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		double ans=0;
		for(int x=1;x<=n;x++)
		ans+=1.0*sqrt(1.0*a[x]*a[x]+1.0*b[x]*b[x]);
		double ans2=0;
		for(int x=1;x<=n;x++)
		ans2+=1.0*sqrt(1.0*a[x]*a[x]+1.0*b[n-x+1]*b[n-x+1]);
		printf("%.15lf\n",min(ans,ans2));
	}
}