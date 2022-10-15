#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	int N;
	cin>>N;
	int arr[N],s=0,mini=0,s2=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		s+=arr[i];
	}
	sort(arr,arr+N);
	for(int i=N-1;i>=0;i--){
		if(s2<=s/2){
			s2+=arr[i];
			mini++;
		}
		else break;
	}
	cout<<mini<<"\n";
}
int main(){
	//multitest
	solve();
	return 0;
}