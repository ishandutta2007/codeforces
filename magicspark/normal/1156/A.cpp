#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,ans;
int a[111]; 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i){
			if(a[i]+a[i-1]==5)return puts("Infinite")&0;
			else if(a[i]+a[i-1]==4)ans+=4;
			else ans+=3;
		}
	}
	for(int i=2;i<n;i++)if(a[i-2]==3&&a[i-1]==1&&a[i]==2)ans--;
	puts("Finite");
	cout<<ans<<endl;
	return 0;
}