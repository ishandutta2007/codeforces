#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define ld long double
#define pi 3.14159265358979323846
#define eps 1e-9
#define pmin priority_queue<int,vector<int>,greater<int> >
#define pmax priority_queue<int>
#define foru(a,b) for(int i=a;i<b;i++)
#define ford(a,b) for(int i=a;i>=b;i--)
#define multitest int T;cin>>T;while(T--)solve();
#define mset(a,b) memset(a,b,sizeof(a))
inline void no(){
	cout<<"NO\n";
}
inline void yes(){
	cout<<"YES\n";
}
const int omg=1e9,mod=1e9+7;
	char s[3010];
void solve(){
	int N;
	cin>>N>>s;
	int lptr=-1,rptr=-1,re=0;
	for(int i=N-1;i>=0;i--){
		if((s[i]-'0')&1){
			re++;
			if(re==1)lptr=i;
			if(re==2)rptr=i;
		}
	}
	if(re<=1)puts("-1");
	else{
		if(!(re&1)){s[lptr+1]='\0';}
		else s[rptr+1]='\0';
		cout<<s<<"\n";
	}
}
signed main(){
	multitest
	//solve();
	return 0;
}