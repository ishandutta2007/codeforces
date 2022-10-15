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
	int n;
	cin>>n;
	int arr[n],s=0,xs=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s+=arr[i];
		xs^=arr[i];
	}
	cout<<"2\n"<<s+xs<<" "<<xs<<"\n";
	return;
}
signed main(){
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}