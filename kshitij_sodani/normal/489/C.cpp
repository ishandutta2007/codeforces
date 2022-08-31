//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
/*mt19937 rng;
rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>*/
int m,s;
bool check(int aa,int bb){
	
	if(bb>=0 and bb<=aa*9){

		return true;
	}
	return false;
}
int ans[100];
int ans2[100];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>m>>s;
	int le=s;
	if(m==1 and s==0){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	if(s>m*9 or s==0){
		cout<<-1<<" "<<-1<<endl;
		return 0;
	}
	int ind=-1;
	for(int i=m-1;i>=0;i--){
		ans[i]=min(9,le);
		le-=ans[i];
		if(ans[i]>0){
			ind=i;
		}
	}
	if(ans[0]==0){
		ans[ind]--;
		ans[0]++;
	}
	int ll=le;
	for(int i=0;i<m;i++){
		ans2[i]=ans[i];
	}

	le=s;
	for(int i=0;i<m;i++){
		ans[i]=min(9,le);
		le-=ans[i];
	}
	if(ans[0]==0 or ans2[0]==0 or le!=0 or ll!=0){
		cout<<-1<<" "<<-1<<endl;
		return 0;
	}
	for(int i=0;i<m;i++){
		cout<<ans2[i];
	}
	cout<<" ";
	for(int i=0;i<m;i++){
		cout<<ans[i];
	}
	cout<<endl;

	/*for(int i=0;i<m;i++){
		for(int j=0;j<10;j++){
			if(i==0 and j==0){
				continue;
			}
			if(check(m-i-1,le-j)){
				cout<<j;
				le-=j;
				break;
			}
		}
	}
	cout<<" ";
		le=s;
*/
	


 
 
	return 0;
}