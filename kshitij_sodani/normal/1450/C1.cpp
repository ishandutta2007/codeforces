//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
string ans[301];
string ss[301];
llo co[3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<3;i++){
			co[i]=0;
		}
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			ss[i]=s;
			ans[i]="";
			for(int j=0;j<n;j++){
				if(s[j]=='X'){
					co[(i+j+3)%3]++;
				}
				/*else{
					ans[i]+=".";
				}*/
			}
		}
		int mi=n*n+1;
		int ind=0;
		for(int i=0;i<3;i++){
			if(co[i]<mi){
				mi=co[i];
				ind=i;
			}
		}
		//cout<<ind<<endl;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ss[i][j]=='X'){
					if((i+j+3)%3==ind){
						ans[i]+='O';
					}
					else{
						ans[i]+='X';
					}
				}
				else{
					ans[i]+=".";
				}
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<endl;
		}

	}














 
	return 0;
}