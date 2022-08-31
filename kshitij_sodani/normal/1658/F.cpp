
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo pre[200001];
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
			llo n,m;
			cin>>n>>m;

			string s;
			cin>>s;
			llo x=0;
			for(llo i=0;i<n;i++){
				it[i]=s[i]-'0';
				x+=it[i];
				pre[i+1]=pre[i]+it[i];
			}
			if((x*m)%n==0){
				llo y=(x*m)/n;
				llo ans=3;
				vector<pair<llo,llo>> xx;
				for(llo i=m-1;i<n;i++){
					if(pre[i+1]-pre[i+1-m]==y){
						if(ans>1){
							ans=1;
							xx.clear();
							xx.pb({i+1-m+1,i+1});
						}
					}
				}
				for(llo i=0;i<m-1;i++){
					if(pre[i+1]+pre[n]-pre[n-(m-(i+1))]==y){
						if(ans>2){
							ans=2;
							xx.clear();
							xx.pb({1,i+1});
							xx.pb({n-(m-(i+1))+1,n});
						}
					}
				}
				cout<<ans<<endl;
				for(auto j:xx){
					cout<<j.a<<" "<<j.b<<endl;
				}
			}
			else{
				cout<<-1<<endl;
			
			}




	}






	return 0;
}