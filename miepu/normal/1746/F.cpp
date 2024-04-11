#include<bits/stdc++.h>
#define int long long
const int N=300005;
const int K=27;
using namespace std;

mt19937 Rnd(114514);

map<int,int> id;
signed a[K][N];
signed A[K][N<<1],cnt;
int n,q;
struct BIT{
    int a[N];
    void add(int k,int p){while(k<=n)a[k]+=p,k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans+=a[k],k-=k&-k;return ans;}
}T[K];

void chg(int i,int j){
	if(id.find(j)==id.end()){
		id[j]=++cnt;
		for(int I=0;I<K;I++)A[I][cnt]=Rnd()%2000000000;//1e12
	}
	j=id[j];
	for(int I=0;I<K;I++){
		int P=A[I][j];
		T[I].add(i,P-a[I][i]);
		a[I][i]=P;
	}
}

bool check(int l,int r,int k){
	for(int I=0;I<K;I++){
		if((T[I].sum(r)-T[I].sum(l-1))%k)
			return 0;
	}
	return 1;
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		chg(i,x);
	}
	for(int i=1;i<=q;i++){
		int op=2;cin>>op;
		if(op==1){
			int x=1,y=1;cin>>x>>y;
			chg(x,y);
		}else{
			int l=1,r=n,k=1;cin>>l>>r>>k;
			cout<<(check(l,r,k)?"YES":"NO")<<'\n';
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}