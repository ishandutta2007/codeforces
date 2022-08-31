//plase fix weird order of queue
//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
llo t;
llo it[1001][1001];
llo tt[1001][1001];
llo n,m;
llo ind[3];
llo su[3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		for(llo i=0;i<3;i++){
			ind[i]=i;
			su[i]=0;
		}
		cin>>n>>m;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				cin>>it[i][j];
 
 
			}
		}
		string s;
		cin>>s;
		/*llo co=0;
		llo co2=0;
		llo co3=0;
		llo co4=0;
		vector<llo> kk;*/
		//
		for(llo i=0;i<m;i++){
			if(s[i]=='L'){
				su[ind[1]]--;
				su[ind[1]]=(su[ind[1]]+n)%n;
			}
			else if(s[i]=='R'){
				su[ind[1]]++;
				su[ind[1]]=(su[ind[1]]+n)%n;
			}
			else if(s[i]=='U'){
				su[ind[0]]--;
				su[ind[0]]=(su[ind[0]]+n)%n;
			}
			else if(s[i]=='D'){
				su[ind[0]]++;
				su[ind[0]]=(su[ind[0]]+n)%n;
			}
			else if(s[i]=='I'){
				//swap(su[ind[1]],su[ind[2]]);
				swap(ind[1],ind[2]);
			}
			else{
			//	swap(su[ind[0]],su[ind[2]]);
				swap(ind[0],ind[2]);
			}
		}
		/*for(llo i=0;i<3;i++){
			cout<<ind[i]<<",";
		}
		cout<<endl;
		for(llo i=0;i<3;i++){
			cout<<su[i]<<',';
		}
		cout<<endl;*/
		//cout<<co<<":"<<co2<<endl;
		//swap(co,co2);
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				vector<llo> ss={i,j,it[i][j]-1};
				/*llo xx,yy,zz;
				for(llo k=0;k<3;k++){
					if(ind[k]==0){
						xx=k;
					}
					else if(ind[k]==1){
						yy=k;
					}
					else{
						zz=k;
					}
				}*/
				tt[(ss[ind[0]]+su[ind[0]])%n][(ss[ind[1]]+su[ind[1]])%n]=((ss[ind[2]]+su[ind[2]])%n)+1;
			}
		}
		/*for(llo i=co;i<co+n;i++){
			for(llo j=co2;j<co2+n;j++){
				tt[i-co][j-co2]=it[i][j];
			}
		}*/
		/*for(auto j:kk){
			if(j==0){
				re();
 
			}
			else{
				re2();
			}
		}*/
		/*co3%=2;
		co4%=2;
		//cout<<co3<<endl;
		if(co3){
			for(llo i=0;i<n;i++){
				for(llo j=0;j<n;j++){
					ee[i][it[i][j]-1]=j+1;
				}
			}
			for(llo i=0;i<n;i++){
				for(llo j=0;j<n;j++){
					tt[i][j]=ee[i][j];
				}
			}
		}
		if(co4){
			for(llo i=0;i<n;i++){
				for(llo j=0;j<n;j++){
					ee[j][it[i][j]-1]=i+1;
				}
			}
			for(llo j=0;j<n;j++){
				for(llo i=0;i<n;i++){
					tt[i][j]=ee[j][i];
				}
			}
		}*/
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				cout<<tt[i][j]<<" ";
			}
			cout<<endl;
		}
 
 
	}
 
 
 
 
 
	return 0;
}
 
/*1
3 16
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI*/