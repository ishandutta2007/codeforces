#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	string s1,s2;
	cin>>a>>s1>>s2;
	if (s2=="month"){
		if (a<30){
			cout<<12<<endl;
		}
		else if(a<31){
			cout<<11<<endl;
		}
		else {
			cout<<7<<endl;
		}
	}
	else{
		if (a==6||a==5){
			cout<<53<<endl;
		}
		else{
			cout<<52<<endl;
		}
	}
}