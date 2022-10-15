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
inline int read(){
	int x=0,neg=1;char c=getchar();
    while(c<48||c>57){if(c==45)neg=-neg;c=getchar();}
    while(c>=48&&c<=57){x=(x<<1)+(x<<3)+c-48;c=getchar();}
    return x*neg;
}
inline void no(){
	cout<<"NO\n";
}
inline void yes(){
	cout<<"YES\n";
}
const int omg=1e9,mod=1e9+7;
void solve(){
	int K;
	cin>>K;
	int cnt=-1,sto=0;
	for(int i=5;pow(i,2)<=K;i++){
		if(K%i)continue;
		if(K/i>=5){
			cnt=K/i;
			sto=i;
			break;
		}
	}
	if(cnt==-1)cout<<cnt;
	else for(int i=0;i<sto*cnt;i++)cout<<"aeiou"[(i%cnt+i/cnt)%5];
	//fucking shit
}
signed main(){
	//multitest
	solve();
	return 0;
}