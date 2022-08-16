//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[1000001];
llo vis[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo q;
	cin>>q;
	while(q--){
		llo n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		for(llo i=0;i<=n;i++){
			vis[i]=0;
		}
		for(llo i=0;i<n;i++){
			it[i]=(1-(s[i]-'0'));
		}
		deque<llo> ss;
		for(llo i=0;i<n;i++){
			if(it[i]==1){
				ss.pb(i);
			}
			if(ss.size()){
				if(ss.front()==i-k){
					ss.pop_front();
				}
			}
			if(ss.size()){
				if(i-ss.front()>=30){
					continue;
				}
			}
			if(i>=k-1){
				llo cur=0;
				for(auto j:ss){
					cur+=(1LL<<(i-j));
				}
				//cout<<i<<":"<<cur<<endl;
				if(cur<=n){
					vis[cur]=1;
					//cout<<i<<":"<<cur<<endl;
				}
			}

		}

		llo st=1;
		/*for(llo i=0;i<=n;i++){
			cout<<vis[i]<<",";
		}
		cout<<endl;*/

		for(llo i=0;i<=n;i++){
			if(k<30){
				if(i>=(1LL<<k)){
					break;
				}
			}
			if(vis[i]==0){
				st=0;
				cout<<"YES"<<endl;
				llo cot=k-1;
				for(llo j=0;j<k;j++){
					if(cot<30){
						if((1LL<<cot)&i){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
					else{
						cout<<0;
					}
					cot--;
				}
				cout<<endl;
				break;
			}
		}
		if(st){
			cout<<"NO"<<endl;
		}



	}






 
	return 0;
}