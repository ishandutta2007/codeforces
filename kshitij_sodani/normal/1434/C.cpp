
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 



llo t;
llo aa,bb,cc,dd;
llo eval(llo i){
	llo cot=(i+1)*(aa-bb*cc);
			llo y=-1;
			if(i*dd>=cc){
				y=(i*dd-cc)/dd;
			}
			cot+=(i-y)*cc*bb;
			cot-=((i-y-1)*(i-y)*dd*bb)/2;
			return cot;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		
		cin>>aa>>bb>>cc>>dd;
		if(dd>cc+1){
			if(bb*cc-aa<0){
				cout<<-1<<endl;
				continue;
			}
			cout<<aa<<endl;
			continue;
		}
		if(aa>bb*cc){
			cout<<-1<<endl;
			continue;
		}
		llo low=0;
		llo high=(cc+dd-1)/dd;
		while(low<high){
			llo mid=(low+high)/2;
			if(eval(mid)>eval(mid+1)){
				high=mid;
			}
			else{
				low=mid+1;
			}
		}
		cout<<eval(low)<<endl;
		//cout<<-2<<endl;
		//continue;
		/*vector<llo> pp;
		for(llo i=0;;i++){
			llo cot=(i+1)*(aa-bb*cc);
			llo y=-1;
			if(i*dd>=cc){
				y=(i*dd-cc)/dd;
			}
			cot+=(i-y)*cc*bb;
			cot-=((i-y-1)*(i-y)*dd*bb)/2;
			cout<<cot<<",";
			if(i*dd>=cc){
				break;
			}
			if(i==20){
				break;
			}
		}
		cout<<endl;*/







	}



	return 0;
}