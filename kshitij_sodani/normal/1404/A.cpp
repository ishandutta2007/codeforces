
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
int co[300001];
int it[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<k;i++){
			co[i]=-1;
		}
		for(int i=0;i<n;i++){
			char s;
			cin>>s;
			if(s=='0'){
				it[i]=0;
			}
			else if(s=='1'){
				it[i]=1;
			}
			else{
				it[i]=2;
			}
		}
		int st=1;
		for(int i=0;i<n;i++){
			if(it[i]==0){
				if(co[i%k]==1){
					st=0;
				}
				co[i%k]=0;
			}
			else if(it[i]==1){
				if(co[i%k]==0){
					st=0;
				}
				co[i%k]=1;
			}
		}
		if(st==0){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			if(it[i]==2){
				if(co[i%k]!=-1){
					it[i%k]=co[i%k];
				}
			}
		}
		int coo[2];
		coo[0]=0;
		coo[1]=0;
		for(int i=0;i<k;i++){
			if(it[i]!=2){
				coo[it[i]]+=1;
			}
		}
		if(coo[0]>k/2 or coo[1]>k/2){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}


	return 0;
}