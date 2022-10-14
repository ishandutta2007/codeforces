#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		if(x>y){
			swap(x,y);
		}
		if(x>0 or y==0){
			cout<<-1<<endl;
			continue;
		}
		if((n-1)%y==0){
			int cur=1;
			for(int i=0;i<n-1;i++){

				cout<<cur<<" ";
				if(i%(y)==(y-1)){
					cur+=y+1;
					if(i>y-1){
						cur--;
					}
				}
			}
			cout<<endl;
		}
		else{
			cout<<-1<<endl;
		}

}


	return 0;
}