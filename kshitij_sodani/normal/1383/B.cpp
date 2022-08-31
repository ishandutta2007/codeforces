
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
int it[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int st=0;
		for(int j=29;j>=0;j--){
			int x=0;
			int y=0;
			for(int i=0;i<n;i++){
				if(it[i]&(1<<j)){
					x+=1;
				}
				else{
					y+=1;
				}
			}
			if(x%2==0){
				continue;
			}
			if(x%4==3 and y%2==0){
				cout<<"LOSE"<<endl;
			}
			else{
				cout<<"WIN"<<endl;
			}
			st=1;
			break;
		}
		if(st==0){
			cout<<"DRAW"<<endl;
		}
	}


	return 0;
}