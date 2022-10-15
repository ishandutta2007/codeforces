#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
/*inline int read(){
	int x=0,neg=1;register int c=getchar_unlocked();
	while(c<48||c>57){if(c==45)neg=-neg;c=getchar_unlocked();}
	while(c>=48&&c<=57){x=(x<<1)+(x<<3)+c-48;c=getchar_unlocked();}
	return x*neg;
}
inline void write(int x){
	if(x<0){
		putchar_unlocked(45);
		write(-x);
	}
	if(x>9)write(x/10);
	putchar_unlocked(x%10+48);
}*/
void solve(){
	int n,k;
	cin>>n>>k;
	// some interactions go here
	k++;
	vector<int> ans;
	for(int i=1;i<=k;i++){
		cout<<"? ";
		for(int j=1;j<=k;j++){
			if(i!=j)cout<<j<<" ";
		}
		cout<<"\n";
		fflush(stdout);
		int a,b;
		cin>>a>>b;
		ans.push_back(b);
	}
	int mx=-1,freq=0;
	for(auto i:ans)mx=max(mx,i);
	for(auto i:ans)freq+=(mx==i);
	cout<<"! "<<freq<<"\n";
	fflush(stdout);
	return;
}
signed main(){
	int t=1;
	//cin>>t;
	while(t--)solve();
	return 0;
}