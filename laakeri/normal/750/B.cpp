#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void nie(){
	cout<<"NO"<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=0;
	int n;
	cin>>n;
	int L=20000;
	for (int i=0;i<n;i++){
		int x;
		string s;
		cin>>x>>s;
		if (s=="South"){
			c+=x;
			if (c>L){
				nie();
			}
		}
		if (s=="North"){
			c-=x;
			if (c<0){
				nie();
			}
		}
		if (s=="East"&&(c==0||c==L)){
			nie();
		}
		if (s=="West"&&(c==0||c==L)){
			nie();
		}
	}
	if (c!=0){
		nie();
	}
	cout<<"YES"<<endl;
}