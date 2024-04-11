//
#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
 
llo aa[1000001];
llo bb[1000001];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo cc[4];
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo su=0;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
			su-=aa[i];
		}
		for(llo i=0;i<n;i++){
			cin>>bb[i];
			su+=bb[i];
		}
		if(su<0){
			cout<<"NO"<<endl;
			continue;
		}
		su=0;
		int st=1;
		for(int i=0;i<2*n;i++){
			su=min((llo)0,bb[(i+n-1)%n]-aa[i%n]+su);
			if(su+bb[i%n]<0){
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