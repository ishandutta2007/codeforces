#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

int pre[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+(s[i-1]-'a'+1);
	}

	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<endl;
	}











	return 0;
}