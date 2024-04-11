//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
string a,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	int dif=0,chg=0;
	for(int i=0;i<b.size();i++){
		if(a[i]!=b[i])dif=1-dif;
	}
	for(int i=0;i<(int)b.size()-1;i++){
		if(b[i]!=b[i+1]){
			chg^=1;
		}
	}
	int ans=dif;
	for(int i=0;i<(int)a.size()-(int)b.size();i++){
		dif^=chg;
		if(a[i+(int)b.size()]!=b.back())dif^=1;
		if(a[i]!=b[0])dif^=1;
		ans+=dif;
	}
	cout<<(int)a.size()-(int)b.size()+1-ans<<endl;
	return 0;
}