

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int t;
int co[10];
vector<int> ss[10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		for(int i=0;i<10;i++){
			co[i]=0;
			ss[i].clear();
		}
		int n=s.size();
		for(int i=0;i<n;i++){
			co[s[i]-'0']++;
			ss[s[i]-'0'].pb(i);
		}
		int ans=n-1;
		for(int i=0;i<10;i++){
			if(co[i]>0){
				int val=co[i];
				ans=min(ans,n-val);
			}
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(i==j){
					continue;
				}
				if(ss[i].size() and ss[j].size()){
					int ind=0;
					int ind2=0;
					int co=0;
					int ba=-1;
					int ans2=0;
					while(ind<ss[i].size() or ind2<ss[j].size()){
						if(co==0){
							while(ind<ss[i].size()){
								if(ss[i][ind]<=ba){
									ind++;
									continue;
								}
								break;
							}
							if(ind==ss[i].size()){
								break;
							}
							ba=ss[i][ind];
						}
						else{
							while(ind2<ss[j].size()){
								if(ss[j][ind2]<=ba){
									ind2++;
									continue;
								}
								break;
							}
							if(ind2==ss[j].size()){
								break;
							}
							ans2+=2;
							ba=ss[j][ind2];
						}
						co=1-co;
					}

					ans=min(ans,n-ans2);
				}

			}
		}
		cout<<ans<<endl;



	}


	return 0;
}