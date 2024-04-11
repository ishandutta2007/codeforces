//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo s,n,k;
		cin>>s>>n>>k;
		swap(s,n);
		// n in s compartments
		if(k>n){
			cout<<"NO"<<endl;
			continue;
		}
		if(k==n){
			cout<<"YES"<<endl;
			continue;
		}
		if(s==1){
			cout<<"NO"<<endl;
			continue;
		}
		//s-1 size subset of {1,2,,,n-1}
		llo xx=(n)/(2*k);
		llo su=xx*(k);
		//cout<<n<<":"<<k<<endl;;
		llo le=n-2*su;
		su+=min(le,k);
	//	cout<<11<<endl;
		/*llo zz=(n%(2*k));
		if(zz>0){
			su+=min(zz,k);
		}*/
	//	cout<<su<<endl;
		if(((n-k)%(2*k))<k){
			su--;
			//cout<<11<<endl;
		}
		su--;
	//	cout<<n<<"::"<<k<<":"<<su<<endl;
		/*llo yy=0;
		llo su2=0;
		for(llo i=1;i<=n-1;i++){
			if((i%(2*k))<k){
				su2++;
			}
		}
		cout<<su2<<endl;*/
		if(su<s-1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		//llo cur=((n+2*k-1-zz)+1)/(2);



	}


 
 
 
	return 0;
}