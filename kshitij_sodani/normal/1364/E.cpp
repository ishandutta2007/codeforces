#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back

int query(int aa,int bb){
	cout<<"? "<<aa<<" "<<bb<<endl;

	int x;
	cin>>x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mt19937 rng;
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin>>n;
	int ans[n];
	vector<int> aa;
	for(int i=0;i<n;i++){
		aa.pb(i);
	}
	shuffle(aa.begin(),aa.end(),rng);
	int a=aa[0];
	int b=aa[1];
	int val=query(a+1,b+1);
	int ind=0;
	for(int i=2;i<n;i++){
		int x=query(b+1,aa[i]+1);
		if(x<val){
			a=aa[i];
			val=x;
		}
		else if(x==val){
			b=aa[i];
			val=query(a+1,b+1);
		}

	}
	while(true){
		int i=uniform_int_distribution<int>(0,n-1)(rng);
		if(i==a or i==b){
			continue;
		}
		int x=query(i+1,a+1);
		int y=query(i+1,b+1);
		if(x!=y){
			ind=(x<y)?a:b;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(i==ind){
			ans[i]=0;
			continue;
		}
		ans[i]=query(i+1,ind+1);
	}
	cout<<"! ";
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}