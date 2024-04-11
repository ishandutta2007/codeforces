#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	ll maxv=0;
	ll minv=0;
	ll n;
	vector<char> lol;
	lol.push_back('+');
	while (cin>>s){
		cin>>s;
		if (s=="="){
			cin>>n;
			break;
		}
		lol.push_back(s[0]);
	}
	for (char t:lol){
		if (t=='+') {
			maxv+=n;
			minv++;
		}
		else{
			maxv--;
			minv-=n;
		}
	}
	if (n>maxv||n<minv){
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<"Possible"<<endl;
	for (int i=0;i<(int)lol.size();i++){
		ll v=min(n-1, maxv-n);
		if (i>0){
			cout<<lol[i]<<" ";
		}
		maxv-=v;
		if (lol[i]=='+'){
			cout<<n-v<<" ";
		}
		else{
			cout<<1+v<<" ";
		}
	}
	cout<<"= "<<n<<endl;
}