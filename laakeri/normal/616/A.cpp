#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.back()=='0') a.pop_back();
	while (b.back()=='0') b.pop_back();
	if ((int)a.size()>(int)b.size()){
		cout<<">"<<endl;
	}
	else if ((int)a.size()<(int)b.size()){
		cout<<"<"<<endl;
	}
	else{
		for (int i=(int)a.size()-1;i>=0;i--){
			if (a[i]>b[i]){
				cout<<">"<<endl;
				return 0;
			}
			if (b[i]>a[i]){
				cout<<"<"<<endl;
				return 0;
			}
		}
		cout<<"="<<endl;
	}
}