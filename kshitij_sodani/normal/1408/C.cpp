
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

long double it[100002];
long double xx=0.00000000001;
long double pre[100002];
long double pre2[100002];
int n,l;
long double val;
bool check(long double mid){
	//return reach 1<=reach2

	long double c1=0;
	int co=1;
	for(int i=1;i<=n+1;i++){
		if(it[i]<=mid){
			c1+=(it[i]-it[i-1])/co;
		}
		else{
			c1+=(mid-it[i-1])/co;
			break;
		}
		co++;
	}
	long double c2=0;
	co=1;
	for(int i=n;i>=0;i--){
		if(it[i]>=mid){
			c2+=(it[i+1]-it[i])/co;
		}
		else{
			c2+=(it[i+1]-mid)/co;
			break;
		}
		co++;
	}
	val=c1;
	return c1<=c2;
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		;
		cin>>n>>l;
		for(int i=0;i<n;i++){
			cin>>it[i+1];
		}

		it[n+1]=l;
		long double low=0;
		long double high=l;
		for(int i=0;i<1000;i++){
			long double mid=(low+high)/2;
			//cout<<mid<<endl;

			if(check(mid)){
				low=mid;
			}
			else{
				high=mid;
			}
		}
		check(low);
		//cout<<low<<endl;
		cout<<setprecision(10)<<val<<endl;






	}








	return 0;
}