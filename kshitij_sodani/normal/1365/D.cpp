#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
//#define endl '\n'
int t,n,m;
int it[50][50];
pair<int,int> par[50][50];
pair<int,int> find(int i,int j){
	if(par[i][j].a==i and par[i][j].b==j){
		return {i,j};
	}
	par[i][j]=find(par[i][j].a,par[i][j].b);
	return par[i][j];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n>>m;
		char s;
		int co=0;
		vector<pair<int,int>> kk;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				par[i][j]={i,j};
				cin>>s;
				if(s=='.'){
					it[i][j]=0;
				}
				else if(s=='#'){
					it[i][j]=1;
				}
				else if(s=='B'){
					it[i][j]=2;
					kk.pb({i,j});
				}
				else{
					it[i][j]=3;
					co+=1;
				}
			}
		}
	
		int st=0;
	/*	if(it[n-1][m-1]==2){
			st=1;
		}
		if(co and n>1){
			if(it[n-2][m-1]==2){
				st=1;
			}
		}
		if(co and m>1){
			if(it[n-1][m-2]==2){
				st=1;
			}
		}
		if(co and m>1 and n>1){
			if(it[n-2][m-2]==2){
				st=1;
			}
		}
		if(st==1){
			cout<<"No"<<endl;
			continue;
		}*/

		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				if(3==it[i][j+1] and it[i][j]==2){
					st=1;
				}
				if(2==it[i][j+1] and it[i][j]==3){
						st=1;
					}
		

			}
		}

		
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m;j++){
				if(3==it[i+1][j] and it[i][j]==2){
					st=1;
				}
				if(2==it[i+1][j] and it[i][j]==3){
					st=1;
				}
			}
		}
		for(auto i:kk){
			//cout<<i.a<<"::"<<i.b<<endl;
			if(i.a>0){
				//if(it[i.a-1][i.b]==0){
				it[i.a-1][i.b]=1;
				
			}
			if(i.b>0){
				it[i.a][i.b-1]=1;
			}
			if(i.a<n-1){
				it[i.a+1][i.b]=1;
			}
			if(i.b<m-1){
				it[i.a][i.b+1]=1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				if((it[i][j]==0 or it[i][j]==3) and (it[i][j+1]==0 or it[i][j+1]==3)){
					pair<int,int> aa=find(i,j);
					pair<int,int> bb=find(i,j+1);
					par[aa.a][aa.b]={bb.a,bb.b};
				}				
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m;j++){
				if((it[i][j]==0 or it[i][j]==3) and (it[i+1][j]==0 or it[i+1][j]==3)){
					pair<int,int> aa=find(i,j);
					pair<int,int> bb=find(i+1,j);
					par[aa.a][aa.b]={bb.a,bb.b};
				}				
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				pair<int,int> aa=find(i,j);
				if(it[i][j]==3){
			//		cout<<i<<","<<j<<","<<aa.a<<","<<aa.b<<endl;

					if(aa.a!=n-1 or aa.b!=m-1){
					//	cout<<i<<","<<j<<","<<aa.a<<","<<aa.b<<endl;
						st=1;
					}
				}
			}
		}
		if(st==0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

	}

	

	return 0;
}