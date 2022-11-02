#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

map<int, int> me;

int k;
int gets(int a){
	if (a==0) return 0;
	if (a==1) return 1;
	if (a>10&&a%2==1) return 0;
	if (me.count(a)) return me[a];
	set<int> lol;
	lol.insert(gets(a-1));
	if (a%2==0){
		if (k==0) lol.insert(gets(0));
		else lol.insert(gets(a/2));
	}
	for (int j=0;j<5;j++){
		if (lol.count(j)==0){
			me[a]=j;
			return j;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>k;
	k%=2;
	int x=0;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		x^=gets(a);
	}
	if (x>0){
		cout<<"Kevin"<<endl;
	}
	else{
		cout<<"Nicky"<<endl;
	}
}