#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}




struct node{
    int ch[2];
    int val;
    int h;
    node(){
        ch[0]=ch[1]=val=h=-1;
    }
};
int tail;
node pool[2*200000+1333];


int calcmin(int u,int w){
    if(pool[u].h<pool[w].h)swap(u,w);
    if(pool[u].h==-1){
        return pool[u].val^pool[w].val;
    }

    if(pool[u].h==pool[w].h)return min(calcmin(pool[u].ch[0],pool[w].ch[0]),calcmin(pool[u].ch[1],pool[w].ch[1]));        
    
    int c=pool[w].val>>pool[u].h&1;
    if(pool[u].ch[c]!=-1)return calcmin(pool[u].ch[c],w);
    return calcmin(pool[u].ch[c^1],w);
}

int N;
int A[222222];
int ans=0;

int solve(int l,int r,int k){
    if(l==r)return -1;
    if(k==-1){
        int v=tail++;
        pool[v].val=A[l];
        return v;
    }
    int m=l;
    while(m<r&&(A[m]>>k&1)==0)m++;
    

    int u=solve(l,m,k-1);
    int w=solve(m,r,k-1);
    int v;
    if(u==-1)return w;
    if(w==-1)return u;
    
    ans+=calcmin(u,w);
    v=tail++;
    pool[v].ch[0]=u;
    pool[v].ch[1]=w;
    pool[v].val=pool[u].val;
    pool[v].h=k;
    return v;
}
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    sort(A,A+N);

    solve(0,N,29);
    cout<<ans<<endl;
    return 0;
}