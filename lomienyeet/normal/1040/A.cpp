#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
void solve(){
	//fuck
	int N,W,B;
	cin>>N>>W>>B;
	int arr[100];
	for(int i=0;i<N;i++)cin>>arr[i];
	int mini,maxi;
	if(W<=B){
		mini=W;
		maxi=B;
	}
	else{
		mini=B;
		maxi=W;
	}
	int start=0,end=N-1,cost=0;
	while(start<=end){
		if(arr[start]==arr[end] and arr[start]==2){
			if(start!=end)cost+=2*mini;
			else cost+=mini;
		}
		if(arr[start]!=arr[end]){
			if(arr[start]!=2 and arr[end]!=2){
				cout<<"-1\n";
				return;
			}
			if(arr[start]==0 ||arr[end]==0)cost+=W;
			else if(arr[start]==1||arr[end]==1)cost+=B;
		}
		start++;
		end--;
	}
	cout<<cost<<"\n";
}
	
int main(){
	ll T=1;
	//cin>>T;
	while(T--)solve();
}