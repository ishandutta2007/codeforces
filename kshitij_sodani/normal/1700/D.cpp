#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo n;
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo ma=0;
	llo su=0;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		su+=it[i];
		ma=max(ma,((su+i)/(i+1)));
	}
	llo q;
	cin>>q;
	while(q--){
		llo x;
		cin>>x;
		if(x<ma){
			cout<<-1<<endl;
		}
		else{
			cout<<((su-1)/x)+1<<endl;
		}
	}


 
 
 
 
 
	return 0;
}