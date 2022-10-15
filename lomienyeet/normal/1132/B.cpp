#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define multitest int T;cin>>T;while(T--)solve();
const int MAXN=3e5+5;
ll arr[MAXN];
void solve(){
	ll N,M;
	cin>>N;
	for(int i=1;i<=N;i++)cin>>arr[i];
	sort(arr+1,arr+N+1);
	for(int i=1;i<=N;i++)arr[i]+=arr[i-1];
	cin>>M;
	for(int i=1;i<=M;i++){
		int query;
		cin>>query;
		cout<<arr[N]-arr[N-query+1]+arr[N-query]<<"\n";
	}
}
int main(){
	//multitest
	solve();
}