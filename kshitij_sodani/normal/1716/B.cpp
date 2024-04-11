#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;


int ans[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cur=1+(n-2)+1;
		cout<<cur<<endl;
		for(int i=0;i<n;i++){
			ans[i]=i+1;
		}
		int x=0;
		for(int i=0;i<cur;i++){
			for(int j=0;j<n;j++){
				cout<<ans[j]<<" ";
			}
			cout<<endl;
			if(x+1<n){
				swap(ans[x],ans[x+1]);
				x+=1;
			}
			/*else{
				swap(ans[n-1],ans[n-2]);
			}*/
		}

	}	








	return 0;
}