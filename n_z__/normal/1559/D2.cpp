#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
int Fa[2][1000001];
inline int Find(int op,int X)
{
    return X==Fa[op][X]?X:Fa[op][X]=Find(op,Fa[op][X]);
}
inline void Merge(int op,int X,int Y)
{
    int x=Find(op,X),y=Find(op,Y);
    if(x<y)swap(x,y);
    Fa[op][x]=y;
}
inline bool Check(int op,int X,int Y)
{
    return Find(op,X)==Find(op,Y);
}
inline void Init(int n)
{
	for(int x=1;x<=n;x++)
	Fa[0][x]=Fa[1][x]=x;
}
pair<int,int>aans[10000001];
inline void bcj()
{
	int n,m1,m2;
    cin>>n>>m1>>m2;
    Init(n);
    for(int x=1;x<=m1;++x)
	{
		int b,c;
        cin>>b>>c;
        Merge(0,b,c);
    }
    for(int x=1;x<=m2;++x)
	{
		int b,c;
        cin>>b>>c;
        Merge(1,b,c);
    }
    int ans=0;
    for(int x=2;x<=n;x++)
    if(Check(0,1,x)==false&&Check(1,1,x)==false)ans++,aans[ans]=make_pair(1,x),Merge(0,1,x),Merge(1,1,x);
    int q1=ans,q2=ans;
    for(int x=2;x<=n;x++){
    if(Fa[0][x]==x)++q1,aans[q1].first=x;
    if(Fa[1][x]==x)++q2,aans[q2].second=x;}
    ans=min(q1,q2);
    cout<<ans<<endl;
    for(int x=1;x<=ans;x++)
    cout<<aans[x].first<<' '<<aans[x].second<<endl;
}
int main()
{
	bcj();
}