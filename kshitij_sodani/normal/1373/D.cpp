#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo it[200001];
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
			cin>>it[i];
			if(i%2==0){
				su+=it[i];
			}
		}
		llo ma=0;
		llo ma3=0;
		for(llo i=0;i<n-1;i+=2){
			ma=max((llo)0,it[i+1]-it[i]+ma);
			ma3=max(ma3,ma);
		}
		llo ma2=0;
		for(llo i=2;i<n;i+=2){
			ma2=max((llo)0,it[i-1]-it[i]+ma2);
			ma3=max(ma3,ma2);
		}
		su+=ma3;
		cout<<su<<endl;

	}
	return 0;
}