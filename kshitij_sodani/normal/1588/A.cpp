//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int aa[101];
int bb[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>aa[i];
		}
		for(int i=0;i<n;i++){
			cin>>bb[i];
		}
		sort(aa,aa+n);
		sort(bb,bb+n);
		int st=1;
		for(int i=0;i<n;i++){
			if(aa[i]==bb[i] or aa[i]==bb[i]-1){
			}
			else{
				st=0;
			}
		}
		if(st){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}






 
	return 0;
}