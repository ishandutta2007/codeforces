#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n;
int vis[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int ma=0;
	int ind=0;
	for(int i=1;i<=n;i++){
		int cur=n-i-((n+i-1)/i)+1;
		if(cur>ma){
			ma=cur;
			ind=i;
		}
	}
	int cur=0;
	if(ma==0){
		cout<<0<<endl;
		return 0;
	}
		int le=(n+ind-1)/ind;
		for(int i=0;i<le;i++){
			vis[cur]=2;
			cur=(cur+ind)%n;
		}
	
	//cout<<ma<<":"<<ind<<endl;
	//return 0;
	while(true){
		vector<int> ss;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				ss.pb(i);
				if(ss.size()==ind){
					break;
				}
			}
		}
		if(ss.size()<ind){
			break;
		}

		cout<<ss.size()<<endl;
		for(auto j:ss){
			cout<<j+1<<" ";
			vis[j]=1;
		}
		cout<<endl;
		int x;
		cin>>x;
		x--;
		for(int i=0;i<ind;i++){
			if(vis[x]==1){
				vis[x]=0;
			}
			//vis[x]=0;
			x=(x+1)%n;
		}
	}




	cout<<0<<endl;



	return 0;
}