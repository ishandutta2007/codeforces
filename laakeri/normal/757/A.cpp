#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int cnt[300];
int cntn[300];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string b="Bulbasaur";
	for (int i=0;i<(int)b.size();i++){
		cntn[b[i]]++;
	}
	string s;
	cin>>s;
	for (char c:s){
		cnt[c]++;
	}
	int v=(int)s.size();
	for (int i=0;i<300;i++){
		if (cntn[i]>0){
			v=min(v, cnt[i]/cntn[i]);
		}
	}
	cout<<v<<endl;
}