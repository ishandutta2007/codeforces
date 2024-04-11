#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int n,p;
int it[100001];
int co[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>p;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	vector<int> ans;
	for(int i=0;i<=2001;i++){
		for(int j=0;j<n;j++){
			co[j]=0;
		}
		int kk=0;
		for(int j=0;j<n;j++){
			int y=it[j]-i;
			if(y>=n){
				kk=1;
				break;
			}
			co[max(y,0)]+=1;
			
		}
		if(kk==1){
			continue;
		}
		int cur=0;
		int st=0;
		for(int j=0;j<n;j++){
			cur+=co[j];
			int ac=(cur-j);
		//	cout<<ac<<endl;
			if(ac<0){
				st=1;
				break;
			}
			if(ac%p==0){
				st=1;
			}
		}
		if(st==0){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j<<" ";
	}
	cout<<endl;





	return 0;
}