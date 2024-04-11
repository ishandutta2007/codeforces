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
	cin>>s;
	int v=0;
	for (char c:s){
		if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') v++;
		if (c=='1'||c=='3'||c=='5'||c=='7'||c=='9') v++;
	}
	cout<<v<<endl;
}