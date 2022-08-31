//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
string it[4];
int co[10][10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin>>it[0]>>it[1]>>it[2];
		for(int i=0;i<3;i++){
			co[i][0]=0;
			co[i][1]=0;	
			for(int j=0;j<2*n;j++){
				co[i][it[i][j]-'0']++;
			}
		}
		int st=0;
		for(int k=0;k<2;k++){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i==j){
						continue;
					}
					if(co[i][k]>=n and co[j][k]>=n and co[i][k]>=co[j][k] and st==0){
						//cout<<i<<":"<<j<<":"<<k<<":"<<co[i][k]<<":"<<co[j][k]<<endl;
						vector<int> ans;
						for(int m=0;m<2*n;m++){
							ans.pb(it[i][m]-'0');
						}
						vector<int> coo;
						coo.pb(0);
						for(int m=0;m<2*n;m++){
							if((it[j][m]-'0')==k){
								coo.pb(0);
							}
							else{
								coo[coo.size()-1]++;
							}
						}
						/*for(auto j:coo){
							cout<<j<<":";
						}
						cout<<endl;*/
						st=1;
					//	continue;
						int le=3*n;
						for(int jj=0;jj<coo[0];jj++){
							cout<<1-k;
							le--;
						}

						llo cot=0;
						for(auto jj:ans){
							cout<<jj;
							le--;
							if(jj==k){
								cot++;
								if(cot<coo.size()){
									for(int kk=0;kk<coo[cot];kk++){
										cout<<1-k;
										le--;
									}
								}
							}
							//cout<<jj;
						}
						for(int jj=0;jj<le;jj++){
							cout<<0;
						}

						cout<<endl;


						st=1;		
						break;
					}
				}

			}
		}
		

	}







 
 
	return 0;
}