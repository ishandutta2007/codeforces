#include<bits/stdc++.h>
#define int long long
#pragma comment(linker, "/STACK:16000000")
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
int n;
int a[222222];
int pw2[33];
set<int> H;
set<pair<int,int> > Data;
signed main(){
	pw2[0]=1;
	for(int i=1;i<33;i++)pw2[i]=pw2[i-1]<<1;
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],H.insert(a[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<31;j++){
			if(H.find(a[i]+pw2[j])!=H.end()){
				Data.insert(make_pair(a[i],a[i]+pw2[j]));
			}
			if(H.find(a[i]-pw2[j])!=H.end()){
				Data.insert(make_pair(a[i],a[i]-pw2[j]));
			}
			if(H.find(a[i]-pw2[j])!=H.end()&&H.find(a[i]+pw2[j])!=H.end()){
				cout<<3<<endl;
				cout<<a[i]-pw2[j]<<" "<<a[i]<<" "<<a[i]+pw2[j]<<endl;
				while(clock()<3000);
				return 0;
			}
		}
	}
	if(!Data.size()){
		cout<<1<<endl;
		cout<<a[0];
		while(clock()<3000);
	}
	else{
		cout<<2<<endl;
		cout<<Data.begin()->first<<" "<<Data.begin()->second<<endl;
		while(clock()<3000);
	}
	return 0;
}