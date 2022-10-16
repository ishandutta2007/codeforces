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
struct Node{
    int l, r;
    mutable long long val;
    Node(int a = -1, int b = -1, long long c = 0){
        l = a, r = b, val = c;
    }
    bool operator < (const Node &a) const{
        return l < a.l;
    }
};
set<Node> st;
int sum;
set<Node>::iterator split(int pos){
    set<Node>::iterator it = st.lower_bound(Node(pos));
    if (it != st.end() && it->l == pos) return it;
    --it; Node tmp = *it; st.erase(it);
    st.insert(Node(tmp.l, pos - 1, tmp.val));
    return st.insert(Node(pos, tmp.r, tmp.val)).first;
}
void assign(int l, int r, long long val){
    sum+=val*(r-l+1);
	set<Node>::iterator itr = split(r + 1), itl = split(l);
    for(auto i=itl; i!=itr; i++) sum-=i->val*(i->r-i->l+1);
    st.erase(itl, itr);
    st.insert((Node){l, r, val});
}
main(){
	int n,q;
    cin>>n>>q;
    st.insert((Node){1, n, 1});
    sum=n;
    for(int x=1;x<=q;x++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if(k==1)assign(l,r,0);
        else assign(l,r,1);
        cout<<sum<<endl;
    }
}