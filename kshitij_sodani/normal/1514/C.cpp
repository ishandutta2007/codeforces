//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo cur=1;
	int cot=0;
	for(llo i=1;i<n;i++){
		if(__gcd(n,i)==1){
			cur=(cur*i)%n;
			cot++;
		}
	}
	int st=-1;

	if(cur==1){
		cout<<cot<<endl;
		
	}
	else{
		st=cur;
		cout<<cot-1<<endl;
	}
	for(llo i=1;i<n;i++){
		if(__gcd(n,i)==1){
			if(st!=i){
				cout<<i<<" ";
			}
		}
	}
	cout<<endl;
	//cout<<cur<<endl;




 
 
	return 0;
}