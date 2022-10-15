#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define debug(n) cout<<"DEBUG1 "<<n<<"\n";
#define debug2(n, m) cout<<"DEBUG2 "<<n<<' '<<m<<"\n";
#define debug3(n, m, x) cout<<"DEBUG3 "<<n<<' '<<m<<' '<<x<<"\n";
#define ss_def stringstream ss
#define upzero(n) if(n<0) n =0
#pragma GCC optimize("Ofast")
using namespace std;
ll int BtoPmodM(ll int b,ll int p,ll int m){
    b%=m;
    if(p==0) return 1;
    else if(p%2==0) return (BtoPmodM(b,p/2,m)*BtoPmodM(b,p/2,m))% m;
    else if(p%2==1) return (BtoPmodM(b,(p-1)/2, m)*BtoPmodM(b,(p-1)/2, m)*b)%m;
    else return 0;
}
ll int gcd(ll int a,ll int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
bool coprime(ll int a,ll int b){
    if(gcd(a,b)==1) return true;
    else return false;
}
ll int factModP(ll int n,ll int p){
    ll int fac[n-1];
    fac[0]=1;
    for(ll int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%p;
    }
    return fac[n];
}
ll int power(ll int x,ll int y,ll int p){
    ll int res=1;
    x=x%p;
    while(y>0){ 
        if(y&1) res=(res*x)%p; 
        y/=2; 
        x=(x*x)%p; 
    } 
    return res; 
}
ll int modInverse(ll int n,ll int p){
    return power(n,p-2,p); 
}
ll int nCrModP(ll int n, ll int r,ll int p){
    if(r==0) return 1;
    else if(r>n) return 0;
    ll int fac[n+1]; 
    fac[0]=1; 
    for(ll int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%p; 
    }
    return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r],p)%p)%p; 
}
ll int nCr(ll int n,ll int r){
    ll int ans=1;
    if(r>=n-r){
        for(ll int i=r+1;i<=n;i++) ans*=i;
        for (ll int i=1;i<=n-r;i++) ans/=i;
    }
    else{
        for(ll int i=n-r+1;i<=n;i++) ans*=i;
        for(ll int i=1;i<=r;i++) ans/=i;
    }
    return ans;
}
ll int string_to_int(string str){
	int strleng=str.length();
	ll int ans=0;
	if(str[0]=='-'){
		for(int i=1;i<strleng;i++) ans+=pow(10,strleng-i-1)*(str[i]-48);
		ans = 0 - ans;
		return ans;
	}
	for(int i=0;i<strleng;i++) ans+=pow(10,strleng-i-1)*(str[i]-48);
	return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
    	string str;
    	cin>>str;
    	int strleng=str.length();
    	int ok=INT_MAX;
    	int A=-1,B=-1,C=-1;
    	for(int i=0;i<strleng;i++){
    		if(str[i]=='1') A=i;
    		else if(str[i]=='2') B=i;
    		else if(str[i]=='3') C=i;
    		if(A!=-1 and B!=-1 and C!=-1){
    			int less=INT_MIN;
    			less=max(less,abs(A-B));
    			less=max(less,abs(A-C));
    			less=max(less,abs(B-C));
    			ok=min(ok,less+1);
			}
		}
		if(ok==INT_MAX) cout<<"0"<<"\n";
		else cout<<ok<<"\n";
	}
}