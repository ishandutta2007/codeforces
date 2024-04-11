//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo aa[300001];
llo bb[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			char s;
			cin>>s;
			aa[i]=s-'0';
		}
		for(int i=0;i<n;i++){
			char s;
			cin>>s;
			bb[i]=s-'0';
		}

		llo co=0;
		llo co2=0;
		for(int i=0;i<n;i++){
			if(aa[i]==1){
				co++;
			}
		}
		int cur=0;
		int st=1;
		for(int i=n-1;i>=0;i--){
			aa[i]^=cur;
			if((1+i)%2==0){
				if(aa[i]!=bb[i]){
					if(co!=((i+1)/2)){
						st=0;
						break;
					}	
					aa[i]^=1;
					cur^=1;
				}
			}
			if(aa[i]==1){
				co--;
			}
		}
		for(int i=0;i<n;i++){
			if(aa[i]!=bb[i]){
				st=0;
			}
		}
		if(st){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}










 
 
 
	return 0;
}