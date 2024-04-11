#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int N=200200;
struct BIT{
	int a[N];
	void add(int x,int v=1){
		// cerr<<"+ "<<x<<" "<<v<<endl;
		for(;x<N;x+=x&-x){
			a[x]+=v;
		}
	}
	int kth(int k){
		int x=0;
		// cerr<<"? "<<k;
		for(int i=18;i>=0;i--){
			if(x+(1<<i)<N){
				int tot=a[x+(1<<i)];
				if(k>tot){
					k-=tot;
					x+=(1<<i);
				}
			}
		}
		// cerr<<" "<<(x+1)<<endl;
		return x+1;
	}
};
BIT tr;
P p[N];
pair<P,int> q[N];
int a[N];
int ans[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		p[i].first=-a[i];
		p[i].second=i;
	}
	sort(p,p+n);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>q[i].first.first>>q[i].first.second;
		q[i].second=i;
	}
	sort(q,q+m);
	int x=0;
	for(int i=0;i<n;i++){
		tr.add(p[i].second+1);
		while(x<m&&q[x].first.first==i+1){
			// cerr<<q[x].first.first<<" "<<q[x].first.second<<endl;
			ans[q[x].second]=a[tr.kth(q[x].first.second)-1];
			x++;
		}
	}
	for(int i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}