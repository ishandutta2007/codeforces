#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>arr(n);
    vector<bool> flag(m+1);
    for(int i=0;i<n;i++){
		cin>>arr[i];
		flag[arr[i]]=1;
	}
    sort(arr.begin(),arr.end());
    auto ip = unique(arr.begin(),arr.end());
    arr.resize(distance(arr.begin(), ip));
    int ans = arr.back() - arr[0];
    int start = sqrt(m)+1;
    vector<int>last(m+1);
    for(int i=0;i<=m;i++) last[i] = i;
    multiset<int>ms;
    for(int i:arr) ms.insert(last[i]);
    for(int j=start;j>=1;j--){
		for(int i=j;i<=m;i+=j){
			if(i/j>=j){
				if(max(last[i/j],last[j])<last[i]){
					if(flag[i])
						ms.erase(ms.find(last[i]));
						
					last[i] = max(last[i/j],last[j]);
					
					if(flag[i])
						ms.insert(last[i]);
				}
			}
		}
		if(j<=arr[0]){
			ans = min(ans,((*ms.rbegin())-j));
		}
	} 
	cout<<ans<<"\n";
}   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;i++)
		solve();
}