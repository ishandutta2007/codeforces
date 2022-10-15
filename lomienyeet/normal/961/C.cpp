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
	int N;
	cin>>N;
	int arr[4]={0};
	foru(0,4){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				char c;
				cin>>c;
				if((c=='0'&&k%2==j%2)||c=='1'&&k%2!=j%2)arr[i]++;
			}
		}
	}
	sort(arr,arr+4);
	cout<<arr[0]+arr[1]-arr[2]-arr[3]+2*pow(N,2);
}
signed main(){
	//multitest
	solve();
	return 0;
}