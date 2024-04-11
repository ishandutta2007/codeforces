#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
int aa[200001];
int bb[200001];
int vis[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ind=-1;
		for(int i=0;i<n;i++){
			cin>>aa[i];
			if(i>0){
				if(aa[i]<aa[i-1]){
					ind=i;
				}
			}
		}
		int st=1;
		int ma=0;
		for(int i=0;i<n;i++){
			cin>>bb[i];
			ma=max(ma,bb[i]);
			if(bb[i]<aa[i]){
				st=0;
			}
		}
		if(st==0){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			int x=(i+1)%n;
			if(bb[i]>bb[x]+1){
				if(aa[i]!=bb[i]){
					st=0;
				}
			}
		}
		if(st==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
		
	}






	return 0;
}