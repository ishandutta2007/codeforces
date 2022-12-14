#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
template<class T> void _W(const T &x) { cout << x; }
template<class T> void _W(T &x) { cout << x; }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.first); putchar(' '); _W(x.second);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) cout<<' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout<<", "; W(tail...); }
#ifdef CF_DEBUG
 #define debug(...) { cout << "debug : [ "; cout << #__VA_ARGS__; cout << " ] = [ "; W(__VA_ARGS__); cout<<"\b\b ]\n"; }
#else
 #define debug(...) (0)
#endif

const int mod = 1e9+7;

// double time=clock();  printf("%lf\n",clock()-time);
const int N = 2e5+10;
vector<int> q,w;
int a[N],b[N],c[N];
int d[N];
int n,cnt;
void print()
{
	cout<<cnt<<endl;
    for1 cout<<d[i]<<" ";
    cout<<endl;
}
void solve()
{
	q.clear();
	w.clear();
    cin>>n;
    for1 cin>>a[i];
    for1 b[i]=1,d[i]=c[i]=0;
    for1
    {
        if(b[a[i]]) d[i] = a[i],b[a[i]]=0,c[a[i]]=i;
        else q.emplace_back(i);
    }
    for1
    {
        if(b[i]) w.emplace_back(i);
    }
    cnt = n-w.size();
    int t = q.size();
    if(!t) print();
    else if(t==1)
    {
        if(q[0]!=w[0]) d[q[0]]=w[0];
        else d[q[0]] = w[0],swap(d[q[0]],d[c[a[q[0]]]]);
        print();
    }
    else
    {
        d[q[0]] = w[0];
        for2(i,1,q.size()-1)
        {
            d[q[i]]=w[i];
            if(q[i]==w[i]) swap(d[q[i]],d[q[i-1]]);
        }
        if(d[q[0]]==q[0]) swap(d[q[0]],d[q[1]]);
        print();
    }
}
signed main()
{
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}



}