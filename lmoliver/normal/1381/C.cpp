#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=200200;
int b[N];
int a[N];
typedef pair<int,int> P;

priority_queue<P> pq;
int qwq[N];
struct Cmp{
	bool operator()(const P a,const P b){
		return qwq[a.first]!=qwq[b.first]?qwq[a.first]>qwq[b.first]:a.first<b.first;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		for(int i=0;i<=n+1;i++)qwq[i]=0;		
		for(int i=1;i<=n;i++){
			cin>>b[i];
			pq.push(P(++qwq[b[i]],i));
		}
		int mis=0;
		for(int i=1;i<=n+1;i++){
			if(!qwq[i]){
				mis=i;
				break;
			}
		}
		for(int i=0;i<x;i++){
			P w=pq.top();
			pq.pop();
			int bb=b[w.second];
			a[w.second]=bb;
		}
		vector<P> ps;
		int mx=0;
		while(!pq.empty()){
			P p=pq.top();
			mx=max(mx,p.first);
			ps.push_back(P(b[p.second],p.second));
			pq.pop();
		}
		sort(ps.begin(),ps.end(),Cmp());
		// for(size_t i=0;i<ps.size();i++){
			// cerr<<ps[i].first<<" "<<ps[i].second<<endl;
		// }
		for(size_t i=0;i<ps.size();i++){
			a[ps[i].second]=ps[(i+mx)%ps.size()].first;
		}
		int d=n-y;
		for(size_t i=0;i<ps.size();i++){
			int x=ps[i].second;
			if(a[x]==b[x]&&d>0){
				d--;
				a[x]=mis;
			}
		}
		for(size_t i=0;i<ps.size();i++){
			int x=ps[i].second;
			if(a[x]!=mis&&d>0){
				d--;
				a[x]=mis;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==b[i])x--;
		}
		if(x==0){
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)cout<<a[i]<<" ";
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
			// for(int i=1;i<=n;i++)cerr<<a[i]<<" ";
			// cerr<<endl;
		}
	}
	return 0;
}