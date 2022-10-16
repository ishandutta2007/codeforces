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
#define int long long
int s[5001],a[5001][5001];
vector<int>v[5001];
signed main(){
    int n,m;
    cin>>n>>m; 
    int t=sqrt((signed)n);
    while(t*(t+1)<n)t++;
    for(int x=1;x<=t+1;x++)
    for(int y=1;y<=t&&(x-1)*t+y<=n;y++)
    cin>>a[x][y],s[x]+=a[x][y],v[x].insert(lower_bound(v[x].begin(),v[x].end(),a[x][y]),a[x][y]);
    while(m--)
    {
        int op;
        cin>>op;
        if(op==3){
            int x,k;
            cin>>x>>k;
            int x1=(x-1)/t+1;
            int y1=x-(x1-1)*t;
            s[x1]+=k-a[x1][y1];
            v[x1].erase(lower_bound(v[x1].begin(),v[x1].end(),a[x1][y1]));
            a[x1][y1]=k;
            v[x1].insert(lower_bound(v[x1].begin(),v[x1].end(),a[x1][y1]),a[x1][y1]);
        }
        else if(op==1){
            int l,r;
            cin>>l>>r;
            int x1=(l-1)/t+1,x2=(r-1)/t+1;
            int y1=l-(x1-1)*t,y2=r-(x2-1)*t;
            if(x1!=x2){
                int ans=0;
                for(int x=y1;x<=t;x++)
                ans+=a[x1][x];
                for(int x=1;x<=y2;x++)
                ans+=a[x2][x];
                for(int x=x1+1;x<=x2-1;x++)
                ans+=s[x];
                cout<<ans<<endl;
            }
            else{
                int ans=0;
                for(int x=y1;x<=y2;x++)
                ans+=a[x1][x];
                cout<<ans<<endl;
            }
        }
        else{
            int l,r,k;
            cin>>l>>r>>k;
            int x1=(l-1)/t+1,x2=(r-1)/t+1;
            int y1=l-(x1-1)*t,y2=r-(x2-1)*t;
            if(x1!=x2){
                for(int x=y1;x<=t;x++)
                if(a[x1][x]>=k)
                s[x1]-=a[x1][x],v[x1].erase(lower_bound(v[x1].begin(),v[x1].end(),a[x1][x])),a[x1][x]%=k,s[x1]+=a[x1][x],v[x1].insert(lower_bound(v[x1].begin(),v[x1].end(),a[x1][x]),a[x1][x]);
                for(int x=1;x<=y2;x++)
                if(a[x2][x]>=k)
                s[x2]-=a[x2][x],v[x2].erase(lower_bound(v[x2].begin(),v[x2].end(),a[x2][x])),a[x2][x]%=k,s[x2]+=a[x2][x],v[x2].insert(lower_bound(v[x2].begin(),v[x2].end(),a[x2][x]),a[x2][x]);
                for(int x=x1+1;x<=x2-1;x++)
                if(v[x][v[x].size()-1]>=k){
                    for(int y=1;y<=t;y++)
                    if(a[x][y]>=k)
                    s[x]-=a[x][y],v[x].erase(lower_bound(v[x].begin(),v[x].end(),a[x][y])),a[x][y]%=k,s[x]+=a[x][y],v[x].insert(lower_bound(v[x].begin(),v[x].end(),a[x][y]),a[x][y]);
                }
            }
            else{
                for(int x=y1;x<=y2;x++)
                if(a[x1][x]>=k)
                s[x1]-=a[x1][x],v[x1].erase(lower_bound(v[x1].begin(),v[x1].end(),a[x1][x])),a[x1][x]%=k,s[x1]+=a[x1][x],v[x1].insert(lower_bound(v[x1].begin(),v[x1].end(),a[x1][x]),a[x1][x]);
            }
        }
        /*for(int x=1;x<=t+1;x++)
        for(int y=1;y<=t;y++)
        cout<<a[x][y]<<' ';cout<<endl;
        for(int x=1;x<=t;x++)
        cout<<s[x]<<' ';cout<<endl<<endl;*/
    }
}