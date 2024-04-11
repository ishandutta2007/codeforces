//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	vector<int> xx;
	for(int j=0;j<(1<<10);j++){
		pair<int,int> aa={1,0};
		pair<int,int> bb={0,1};
		vector<int> cur;
		for(int i=0;i<10;i++){
			if((1<<i)&j){
				aa.a+=bb.a;
				aa.b+=bb.b;
				cur.pb(0);
			}
			else{
				bb.a-=aa.a;
				bb.b-=aa.b;
				cur.pb(1);
			}

			if(aa.a==0 and aa.b==-1 and bb.a==-1 and bb.b==0){
				xx=cur;
			}
			if(bb.a==0 and bb.b==-1 and aa.a==-1 and aa.b==0){
				xx=cur;
			}

		}			
	}
	/*for(auto j:xx){
		cout<<j<<",";
	}
	cout<<endl;*/
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		vector<pair<int,pair<int,int>>> ans;
		cout<<(3*n)<<endl;
		for(int i=0;i<n;i+=2){
			for(auto j:xx){
				cout<<j+1<<" "<<i+1<<" "<<i+2<<endl;
			}
		}
	}







	return 0;
}