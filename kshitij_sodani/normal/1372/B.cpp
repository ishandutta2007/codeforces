//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=n-1;
		pair<llo,llo> cur={1,n-1};
		for(llo i=1;i*i<=n;i++){
			if(n%i==0){
				llo cot=i*((n/i)-1);
				pair<llo,llo> cur2={i*((n/i)-1),i};
				if(cot<ans and cur2.a!=0){
					ans=cot;
					cur=cur2;
				}
				llo ii=n/i;
				cot=ii*((n/ii)-1);
				cur2={ii*((n/ii)-1),ii};
				if(cot<ans and cur2.a!=0){
					ans=cot;
					cur=cur2;
				}

			}
		}
		cout<<cur.a<<" "<<cur.b<<endl;
	}




 
	return 0;
}