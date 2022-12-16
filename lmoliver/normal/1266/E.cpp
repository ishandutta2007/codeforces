#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(S);N<=(E);N++)
const int N=200200;
int a[N];
LL sum=0;
typedef pair<int,int> P;
map<P,int> w;
int d[N]={0};
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	F(i,1,n){
		cin>>a[i];
		sum+=a[i];
	}
	int q;
	cin>>q;
	while(q--){
		int s,t,u;
		cin>>s>>t>>u;
		P p(s,t);
		if(w.count(p)){
			int x=w[p];
			d[x]--;
			if(d[x]<a[x])sum++;
			w.erase(p);
		}
		if(u){
			if(d[u]<a[u])sum--;
			d[u]++;
			w[p]=u;
		}
		cout<<sum<<endl;
	}
	return 0;
}