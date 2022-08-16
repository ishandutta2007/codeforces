#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n;
int aa[1000001];
int bb[1000001];
int vis[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	string s;
	cin>>s;
	int co=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			aa[i]=1;
			co+=1;
		}
		else{
			aa[i]=0;
		}
	}
	string t;
	cin>>t;
	for(int i=0;i<n;i++){
		if(t[i]=='1'){
			bb[i]=1;
			co-=1;
		}
		else{
			bb[i]=0;
		}
	}
	if(co!=0){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> ind3;
	for(int i=0;i<n;i++){
		if(aa[i]!=bb[i]){
			ind3.pb(i);
		}
	}
	if(ind3.size()==0){
		cout<<0<<endl;
		return 0;
	}

	set<int> ss;
	set<int> tt;
	for(auto i:ind3){
		if(aa[i]==0){
			ss.insert(i);
		}
		else{
			tt.insert(i);
		}
	}
	int ans=0;
	for(auto i:ind3){
		
		if(vis[i]==0){
			ans+=1;
			vis[i]=1;

			int cur=0;
			if(aa[i]==0){
				cur=1;
			}
			int ind=i;
			vector<int> cur2;
			cur2.pb(i);
			while(true){
				if(cur==0){
					auto x=ss.upper_bound(ind);
					if(x==ss.end()){
						break;
					}
					cur2.pb(*x);
				}
				else{
					auto x=tt.upper_bound(ind);
					if(x==tt.end()){
						break;
					}
					cur2.pb(*x);
				}
				ind=cur2.back();
				cur=1-cur;
			}
			if(cur2.size()%2==1){
				cur2.pop_back();
			}
			for(auto j:cur2){
				if(aa[j]==0){
					ss.erase(j);
				}
				else{
					tt.erase(j);
				}
				vis[j]=1;
			}
		}
	}
	cout<<ans<<endl;








	return 0;
}