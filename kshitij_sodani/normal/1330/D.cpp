#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
llo mod=100000007;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		llo d,m;
		cin>>d>>m;
		llo dd[31][31];
		for(int i=0;i<31;i++){
			for(int j=0;j<31;j++){
				dd[i][j]=0;
			}
		}
		for(llo i=0;i<31;i++){
			for(llo j=0;j<31;j++){
				if(j==0){
					dd[i][j]=min(d,2*((llo)1<<i)-1)-(((llo)1<<i)-1);
					dd[i][j]=max(dd[i][j],(llo)0);
					/*if(dd[i][j]>0){
						cout<<i<<" "<<dd[i][j]<<endl;
					}*/
				}
				else{
					dd[i][j]=min(d,2*((llo)1<<i)-1)-(((llo)1<<i)-1);
					dd[i][j]=max(dd[i][j],(llo)0);
					llo tot=0;
					for(llo k=0;k<i;k++){
						tot+=dd[k][j-1];
					}
					dd[i][j]*=tot;
					dd[i][j]%=m;
				}
			}
		}
		llo ans=0;
		for(llo i=0;i<31;i++){
			for(llo j=0;j<31;j++){
				ans+=dd[i][j];

				ans%=m;
			}
		}
		cout<<ans<<endl;
	}







	return 0;
}