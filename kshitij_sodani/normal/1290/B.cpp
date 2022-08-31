#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;

	llo n=s.size();
	//cout<<n<<endl;

	llo it[n];
	for(llo i=0;i<n;i++){
		it[i]=s[i]-'a';
	}	

	llo pre[n][26];
	for(llo i=0;i<26;i++){
		pre[0][i]=0;
	}
	pre[0][it[0]]=1;
	for(llo i=1;i<n;i++){
		for(llo j=0;j<26;j++){
			pre[i][j]=pre[i-1][j];
		}
		pre[i][it[i]]+=1;
	}
	llo q;
	cin>>q;
	while(q--){
		llo l,r;
		cin>>l>>r;
		if(l==r){
			cout<<"Yes"<<endl;
			continue;
		}
		llo co=0;
		llo co2=0;
		for(llo i=0;i<26;i++){
			if(l==1){
				if(pre[r-1][i]>0){
					co+=1;
					co2+=min(pre[r-1][i]-1,(llo)1);
				}

			}

			else if(pre[r-1][i]-pre[l-2][i]>0){
				co+=1;
				co2+=min(pre[r-1][i]-pre[l-2][i]-1,(llo)1);

			}
		}
		//cout<<co<<endl;
		if(co==1){
			cout<<"No"<<endl;
		}
		else{

			if(it[l-1]==it[r-1]){
				if(l==1){
					if(pre[r-1][it[r-1]]>(r-l-1)){
						cout<<"No"<<endl;
						continue;
					}
				}

				else if(pre[r-1][it[r-1]]-pre[l-2][it[r-1]]>(r-l-1)){
					cout<<"No"<<endl;
					continue;
				}
				if(co>=3){
					cout<<"Yes"<<endl;
					continue;
				}
				if(co2==1){
					cout<<"No"<<endl;
				}
				else{
					cout<<"No"<<endl;
				}
				
			}
			else{
				cout<<"Yes"<<endl;
			}
		}

	}






	return 0;
}