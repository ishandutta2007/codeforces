#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

    
struct BinaryIndexedTree{
	int n;
	vector<int>dat;
	BinaryIndexedTree(int n=0):n(n){
		dat.resize(n+1);
	}
	void add(int k,int x){
		for(k++;k<=n;k+=k&-k)dat[k]+=x;
	}
	int sum(int k){
		int ret=0;
		for(k++;k;k-=k&-k)ret+=dat[k];
		return ret;
	}
};

int N,Q;
char str[222222];
int A[222222];
set<int>pos[3];

signed main(){
	scanf("%lld%lld",&N,&Q);
	BinaryIndexedTree bit[3];
	rep(i,3)bit[i]=BinaryIndexedTree(N);
	scanf("%s",str);
	rep(i,N){
		int k;
		if(str[i]=='R')k=0;
		else if(str[i]=='P')k=1;
		else k=2;
		A[i]=k;
		bit[A[i]].add(i,1);
		pos[A[i]].insert(i);
	}

	for(int x=0;x<=Q;x++){
		int p;
		char c;
		int uku;
		if(x){
			scanf("%lld %c",&p,&c);
			p--;
			if(c=='R')uku=0;
			else if(c=='P')uku=1;
			else uku=2;
		}
		else{
			p=0;
			uku=A[0];
		}
		bit[A[p]].add(p,-1);
		pos[A[p]].erase(p);
		A[p]=uku;
		bit[A[p]].add(p,1);
		pos[A[p]].insert(p);

		int ans=N;
		for(int k=0;k<3;k++){
			if(pos[(k+1)%3].size()==0)continue;
			if(pos[(k+2)%3].size()==0){
				ans-=pos[k].size();
				continue;
			}
			int b=*pos[(k+1)%3].begin();
			int bb=*pos[(k+2)%3].begin();
			if(b<bb){
				ans-=bit[k].sum(bb)-bit[k].sum(b);
			}
			int e=*pos[(k+1)%3].rbegin();
			int ee=*pos[(k+2)%3].rbegin();
			if(ee<e){
				ans-=bit[k].sum(e)-bit[k].sum(ee);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;

}