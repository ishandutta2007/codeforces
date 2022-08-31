#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
//#define endl '\n'
llo arr[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	llo ans[13];
	llo cp=-1;
	for(int i=1;i<(1<<13);i++){
		if(__builtin_popcount(i)==7){
			cp+=1;
			if(cp<1000){
				arr[cp]=(llo)i;
			}
		}
	}
	for(llo i=0;i<13;i++){
		ans[i]=0;
	}
	/*for(llo i=0;i<n;i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;*/
	//return 0;
	for(llo i=0;i<13;i++){
		vector<llo> j;
		for(llo k=1;k<n+1;k++){
			if(arr[k-1]&(1<<i)){
				j.pb(k);
			}
		}
		if(j.size()>0){
			cout<<"? "<<(j.size());
			cout<<" ";
			for(auto k:j){
				cout<<k<<" ";
			}
			cout<<endl;
			cin>>ans[i];
		}
	}
	cout<<"! ";
	for(llo i=1;i<n+1;i++){
		llo xx=0;
		for(llo j=0;j<13;j++){
			if((arr[i-1]&(1<<j))==0){
				xx|=ans[j];
			}
		}
		cout<<xx<<" ";
	}
	cout<<endl;


	return 0;
}