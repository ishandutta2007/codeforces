//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,aa,bb;
		cin>>n>>aa>>bb;
		int x=n-2;
		if((aa+bb>x) ){//or aa>((x+1)/2) or bb>(x+1)/2){
			cout<<-1<<endl;
			continue;
		}
		if(abs(aa-bb)>1){
			cout<<-1<<endl;
			continue;
		}
		deque<int> ss;
		for(int i=1;i<=n;i++){
			ss.pb(i);
		}
		for(int i=0;i<n;i++){
			ans[i]=-1;
		}
		if(aa>bb){
			for(int i=1;i<n and i<1+aa*2;i+=2){
				ans[i]=ss.back();
				ss.pop_back();
			}
			for(int i=n-1;i>=0;i--){
				if(ans[i]==-1){
					ans[i]=ss.front();
					ss.pop_front();
				}
			}
			//for(int )
		}
		else{
			for(int i=1;i<n and i<1+bb*2 ;i+=2){
				ans[i]=ss.front();
				ss.pop_front();
				
			}
			if(aa==bb){
				ans[1+(bb-1)*2+1]=ss.back();
				ss.pop_back();
			}
			if(aa==bb){
				for(int i=0;i<n;i++){
					if(ans[i]==-1){
						ans[i]=ss.back();
						ss.pop_back();
					}
				}
			}
			else{
				for(int i=n-1;i>=0;i--){
					if(ans[i]==-1){
						ans[i]=ss.back();
						ss.pop_back();
					}
				}
			}
			/*for(int i=n-1;i>=0;i--){
				if(ans[i]==-1){
					ans[i]=ss.back();
					ss.pop_back();
				}
			}*/
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

	}



 
	return 0;
}