#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define mid(L,R) ((L+R)/2)
struct Node{ int cnt , L , R;
    Node()
    {
        cnt=0;
        L = R = -1;
    }
    Node(int x,int y,int z)
    {
        L = x;
        R = y;
        cnt = z;
    }
}tree[8160001];


int fastscan()
{
    register int n=0;
    char ch=getchar();
    for(;(ch<48||ch>57);ch=getchar())
        ;
    for(;(ch>47&&ch<58);ch=getchar())
        n=(n<<3)+(n<<1)+ch-48;
    return n;
}
int G[1000001];
int A[100001],root[100001],RM[100001],B[100001],V[100001];
int gc = 0 , N;

int build(int L , int R)
{
    ++gc;
    if(L==R)
        return gc;
    int x = gc;
    tree[x] = Node(build(L,mid(L,R)),build(mid(L,R)+1,R),0);
    return x;
}


int update(int L , int R , int root , int idx , int val)
{
    if(L>idx || R<idx)
        return root;
    ++gc;
    if(L==idx&&R==idx)
    {
        tree[gc] = Node(-1,-1,tree[root].cnt+val);
        return gc;
    }
    int x = gc;
    tree[x]=Node(update(L,mid(L,R),tree[root].L,idx,val),update(mid(L,R)+1,R,tree[root].R,idx,val),tree[root].cnt+val);
    return x;
}

int query(int L , int R , int root , int qe , int qr)
{
    if(qr<L || qe>R)return 0;
    if(qe<=L && R<=qr)
        return tree[root].cnt;
    return query(L,mid(L,R),tree[root].L,qe,qr)+
            query(mid(L,R)+1,R,tree[root].R,qe,qr);
}

int go(int L , int R , int root, int lim)
{
	if (L==R) return L;
	ll right=tree[root].R;
	ll right_cnt=tree[right].cnt;
	if (lim<right_cnt) {
		return go(mid(L,R)+1,R,tree[root].R,lim);
	}
	else {
		return go(L,mid(L,R),tree[root].L, lim-right_cnt);
	}
}

int main()
{
    int  M , i , x , y , z;
    N  = fastscan();
    memset(G,-1,sizeof(G));
    for(i=1;i<=N;++i){A[i]=fastscan();}
    root[0] = build(1,N);
    for(i=1;i<=N;++i)
    {
        int p = root[i-1];
        if(G[A[i]]!=-1)
            p = update(1,N,p,G[A[i]],-1);
        root[i] = update(1,N,p,i,1);
        G[A[i]]=i;
    }
    /*M  = fastscan();

    for(;M;--M)
    {
        x = fastscan();
        y = fastscan();
        printf("%d\n",query(1,N,root[y],x,y));
    }*/
    //{
    //	int x=1,y=N;
    //	printf("%d\n",query(1,N,root[y],x,y));
    //}
    for (int k=1;k<=N;k++) {
    	int ans=0;
    	int y=N;
    	while(y>0) {
    		int l=go(1,N,root[y],k);
    		//printf("k:%d y:%d l:%d\n",k,y,l);
    		ans++;
    		if (l==1&&query(1,N,root[y],1,y)<=k) l--;
    		y=l;
    	}
    	printf("%d ",ans);
    }
    printf("\n");

    return 0;
}