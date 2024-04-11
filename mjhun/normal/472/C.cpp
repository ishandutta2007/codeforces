#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

string s[100005][2];
int n;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	fore(i,0,n){
		cin>>s[i][0]>>s[i][1];
		if(s[i][1]<s[i][0])swap(s[i][0],s[i][1]);
	}
	int l=0;
	int p;
	cin>>p;p--;
	fore(i,1,n){
		int p2;
		cin>>p2;p2--;
		if(s[p][l]<s[p2][0])l=0;
		else if(s[p][l]<s[p2][1])l=1;
		else {cout<<"NO"<<endl;return 0;}
		p=p2;
	}
	cout<<"YES"<<endl;
	return 0;
}