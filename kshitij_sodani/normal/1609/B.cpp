//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[100001];
int n,q;
int check(int i){
	if(i<0 or i>=n-2){
		return 0;
	}
	if(it[i]==0 and it[i+1]==1 and it[i+2]==2){
		return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		it[i]=s[i]-'a';
	}
	int ans=0;
	for(int i=0;i<n-2;i++){
		ans+=check(i);
	}
	while(q--){
		int ind;
		cin>>ind;
		ind--;
		char s;
		cin>>s;
		int j=s-'a';
		ans-=check(ind-2);
		ans-=check(ind-1);
		ans-=check(ind);
		
		it[ind]=j;
		ans+=check(ind-2);
		ans+=check(ind-1);
		ans+=check(ind);
		cout<<ans<<endl;
	}




 
	return 0;
}