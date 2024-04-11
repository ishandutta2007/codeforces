#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n;
string s;
int a[N];

void solve(){
	cin>>n;n<<=1;
	cin>>s;s='0'+s;
	int f0=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1];
		if(s[i]=='(')a[i]++;
		else a[i]--; 
		f0&=a[i]>=0;
	}
	if(f0){
		cout<<"0"<<endl;
		return ;
	}
	int l,r,mx=0;
	for(int i=n;i>=1;i--)if(a[i]<0)l=i;
	for(int i=1;i<=n;i++)if(a[i]<0)r=i;
	for(int i=1;i<=n;i++)if(a[i]>a[mx])mx=i;
	int L=l,R=r;
	for(int i=l;i>=1;i--)
		if(a[i-1]>a[L-1])L=i;
	for(int i=r;i<=n;i++)
		if(a[i]>a[R])R=i;
	reverse(s.begin()+L,s.begin()+R+1);
	int f1=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1];
		if(s[i]=='(')a[i]++;
		else a[i]--; 
		f1&=a[i]>=0;
	} 
	if(f1){
		cout<<"1"<<endl;
		cout<<L<<' '<<R<<endl;
	}else{
		cout<<"2"<<endl;
		cout<<1<<' '<<mx<<endl;
		cout<<mx+1<<' '<<n<<endl;
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}