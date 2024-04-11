#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int n,s,ans,a[N];
struct fenwick_tree{
	int tr[N];
	void add(int x,int y){
		for(;x<N;x+=x&-x)tr[x]+=y;
	}
	int ask(int x){
		int res=0;
		for(;x;x&=x-1)res+=tr[x];
		return res;
	}
};
fenwick_tree t1,t2;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		ans+=(i-1)*a[i]+(s+=a[i])-t2.ask(a[i]);
		t1.add(a[i],1);
		for(int j=a[i];j<N;j+=a[i])
			ans-=j*(t1.ask(min(N-1,j+a[i]-1))-t1.ask(j-1)),t2.add(j,a[i]);
		cout<<ans<<" ";
	}
}