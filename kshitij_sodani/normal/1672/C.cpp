#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int it[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int st=0;
		vector<int> ss;
		deque<int> tt;
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(i>0){
				if(it[i]==it[i-1]){
					st++;
					ss.pb(i);
					tt.pb(i);
				}
			}
		}

		if(st<=1){
			cout<<0<<endl;
			continue;
		}
		int ans=max(ss.back()-ss[0]-1,1);
		cout<<ans<<endl;
		//cout<<ss.back()-ss[0]<<endl;
	/*	int ans=0;
		while(tt.size()>1){
			ans++;
			if(true){
				int no=tt.front();
				tt.pop_front();
				int no2=tt.front();
				if(no2==no+1){
					tt.pop_front();
					if(tt.size()){
						if(tt.front()==no2+1){
							continue;
						}
						else{
							tt.push_front(no2+1);
							continue;
						}
					}
					else{
						break;
					}
				}
				tt.push_front(no);
			}
			if(true){
				int no=tt.back();
				tt.pop_back();
				int no2=tt.back();
				if(no2==no+1){
					tt.pop_back();
					if(tt.size()){
						if(tt.back()==no2+1){
							continue;
						}
						else{
							tt.push_back(no2+1);
							continue;
						}
					}
					else{
						break;
					}
				}
				tt.push_back(no);
			}
			int no=tt.front();
			tt.pop_front();
			tt.push_front(no+1);
		}
		cout<<ans<<endl;*/

		
	}








	return 0;
}