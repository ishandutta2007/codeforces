#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void ans(string s){
	cout<<s<<endl;
	exit(0);
}

void nie(){
	cout<<"Impossible"<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t1,t2,t3,t4;
	cin>>t1>>t2>>t3>>t4;
	if (t1==0&&t2==0&&t3==0&&t4==0) ans("1");
	if (t1==0&&t4==0){
		if (t2==0&&t3==0){
			nie();
		}
		if (t2>0&&t3>0){
			nie();
		}
		if (t2==1){
			ans("01");
		}
		if (t3==1){
			ans("10");
		}
		nie();
	}
	ll a=0;
	ll b=0;
	while (a*(a+1)/2<=t1) a++;
	while (b*(b+1)/2<=t4) b++;
	if (a*(a-1)/2!=t1) nie();
	if (b*(b-1)/2!=t4) nie();
	
	if (t2==0&&t3==0){
		if (t1>0&&t4>0){
			nie();
		}
		if (t1>0){
			string s(a, '0');
			ans(s);
		}
		if (t4>0){
			string s(b, '1');
			ans(s);
		}
	}
	if (t1==0){
		if (t2+t3!=b){
			nie();
		}
		string s;
		for (int i=0;i<t3;i++){
			s+='1';
		}
		s+='0';
		for (int i=0;i<t2;i++){
			s+='1';
		}
		ans(s);
	}
	if (t4==0){
		if (t2+t3!=a){
			nie();
		}
		string s;
		for (int i=0;i<t2;i++){
			s+='0';
		}
		s+='1';
		for (int i=0;i<t3;i++){
			s+='0';
		}
		ans(s);
	}
	if (a*b!=t2+t3){
		nie();
	}
	string s;
	for (int i=0;i<a;i++){
		s+='0';
	}
	for (int i=0;i<b;i++){
		s+='1';
	}
	ll h2=a*b;
	ll h3=0;
	int p1=a-1;
	int p2=a+b-1;
	while (h2>t2){
		if (h2-b>=t2){
			swap(s[p1], s[p2]);
			h2-=b;
			h3+=b;
			p1--;
			p2--;
		}
		else{
			while (h2>t2){
				swap(s[p1], s[p1+1]);
				p1++;
				h2--;
				h3++;
			}
		}
	}
	cout<<s<<endl;
}