//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=n;true;i++){
			//vector<llo> kk;
			llo le=i;
			llo st=0;
			while(le>0){
				int x=le%10;
				if(x){
					if(i%x>0){
						st=1;
						break;
					}
				}
				le/=10;
			}
			
			/*for(auto j:kk){
				if(j==0){
					continue;
				}
				st=max(st,i%j);
				if(st>0){
					break;
				}
			}*/
			if(st==0){
				cout<<i<<endl;
				break;
			}
		}
	}

 
	return 0;
}