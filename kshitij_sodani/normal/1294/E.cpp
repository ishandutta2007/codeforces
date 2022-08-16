#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	llo it[n][m];
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			cin>>it[i][j];
		}
	}
	llo mm=n*m-m;
	llo tot=0;
	for(llo j=0;j<m;j++){
		map<llo,llo> aa;
		for(llo i=0;i<n;i++){
			llo k=i*m+j+1-it[i][j];
			if(aa.find(k)==aa.end()){
				aa[k]=1;
			}
			else{
				aa[k]+=1;
			}
		}
		llo mi;
		if(aa.find(0)==aa.end()){
			mi=n;
		}
		else{
			mi=n-aa[0];
		}
		//cout<<mi<<" ";
		for(llo i=0;i<n;i++){
			//llo k=it[i][j];
			llo k=i*m+j+1-it[i][j];
			aa[k]-=1;
		//	cout<<k<<" ";
			if(aa.find(k+mm+m)==aa.end()){
				aa[k+mm+m]=1;
			}
			else{
				aa[k+mm+m]+=1;
			}
			llo cc;
			if(aa.find(i*m+m)==aa.end()){
				cc=n+i+1;
			}
			else{
				cc=n-aa[i*m+m]+i+1;
			}
			mi=min(mi,cc);
		}
		//cout<<mi<<endl;
		tot+=mi;
	}
	cout<<tot<<endl;







	return 0;
}