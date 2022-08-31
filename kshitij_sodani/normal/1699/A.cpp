#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	
		if(n%2==0){
			cout<<(n/2)<<" "<<0<<" "<<0<<endl;

		}
		else{
			cout<<-1<<endl;
		}

	}







	return 0;
}