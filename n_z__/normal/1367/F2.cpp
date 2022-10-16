#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
pair<int,int>a[200001];
set<int>s;
stack<int>q;
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
main(){
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        s.clear();
        int n;
        cin>>n;
        for(int x=0,y;x<n;x++)
        cin>>y,a[x]={y,-x};
        sort(a,a+n);
        for(int x=0,y=0;x<n;x++)
        {
            if(x&&a[x].first-a[x-1].first)
            while(!q.empty())s.insert(q.top()),q.pop();
            q.push(a[x].second);
            for(;!s.empty()&&*s.begin()<a[x].second;y++)
            s.erase(a[y].second);
            ans=max(ans,(int)(s.size()+q.size()));
        }
        cout<<n-ans<<endl;
        while(!q.empty())q.pop();
    }
}