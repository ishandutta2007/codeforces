#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define ld long double
#define pi 3.14159265358979323846
#define eps 1e-9
#define pmin priority_queue<int,vector<int>,greater<int> >
#define pmax priority_queue<int>
#define foru(a,b) for(int i=a;i<b;i++)
#define ford(a,b) for(int i=a;i>=b;i--)
#define multitest int T;cin>>T;while(T--)solve();
#define mset(a,b) memset(a,b,sizeof(a))
inline void no(){
	cout<<"NO\n";
}
inline void yes(){
	cout<<"YES\n";
}
const int omg=1e9,mod=1e9+7,MAXN=1e2+69;
vector<int> v[MAXN];
void solve(){
	int N,M,K;
	cin>>N>>M>>K;
	int arr[N+1],arr2[N+1];
	for(int i=1;i<=N;i++)cin>>arr[i];
	for(int i=1;i<=N;i++){
		cin>>arr2[i];
		v[arr2[i]].pb(arr[i]);
	}
	for(int i=1;i<=M;i++)sort(v[i].begin(),v[i].end(),greater<int>());
	int re=0,cur;
	for(int i=0;i<K;i++){
		cin>>cur;
		if(v[arr2[cur]][0]!=arr[cur])re++;
	}
	cout<<re;
}
signed main(){
	//multitest
	solve();
	return 0;
}