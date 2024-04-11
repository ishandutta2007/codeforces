//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo co[1000001];
vector<llo> xx[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		for(llo i=0;i<=max(n,m);i++){
			co[i]=0;
			xx[i].clear();
		}

		

		for(llo i=0;i<m;i++){
			llo x;
			cin>>x;
			vector<llo> bb;
			for(llo j=0;j<x;j++){
				llo cc;
				cin>>cc;
				cc--;
				co[cc]++;
				xx[i].pb(cc);
			}
		}
		pair<llo,llo> ma={0,0};
		for(llo i=0;i<n;i++){
			ma=max(ma,{co[i],i});
		}
		if(ma.a<=((m+1)/2)){
			cout<<"YES"<<endl;
			for(llo i=0;i<m;i++){
				cout<<xx[i][0]+1<<" ";
			}
			cout<<endl;
		}
		else{
			llo coo=0;

			for(llo i=0;i<m;i++){
				if(xx[i].size()==1){
					if(xx[i][0]==ma.b){
						coo++;
					}
				}
			}
			if(coo>((m+1)/2)){
				cout<<"NO"<<endl;
				continue;
			}
			cout<<"YES"<<endl;
			llo yy=((m+1)/2)-coo;
			for(llo i=0;i<m;i++){
				if(xx[i].size()==1){
					cout<<xx[i][0]+1<<" ";
					continue;
				}
				llo st=1;
				for(auto j:xx[i]){
					if(j==ma.b){
						st=0;
					}
				}
				if(st==0 and yy>0){
					yy--;
					cout<<ma.b+1<<" ";
				}
				else{
					if(xx[i][0]!=ma.b){
						cout<<xx[i][0]+1<<" ";
					}
					else{
						cout<<xx[i][1]+1<<" ";
					}
				}
			}
			cout<<endl;





		}




	}







 
	return 0;
}