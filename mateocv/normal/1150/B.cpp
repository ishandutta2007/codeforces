#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	char t[n][n];
	ll tot=0;
	fore(i,0,n){
		fore(j,0,n){
			cin>>t[i][j];
			tot+=(t[i][j]=='#');
		}
	}
	while(tot<n*n){
		fore(i,0,n){
			fore(j,0,n){
				if(t[i][j]=='.'){
					if((i+2<n)&&(j-1>=0)&&(j+1<n)&&(t[i+1][j]=='.')&&(t[i+1][j-1]=='.')&&(t[i+1][j+1]=='.')&&(t[i+2][j]=='.')){
						tot+=5;
						t[i][j]='#';
						t[i+1][j]='#';
						t[i+1][j-1]='#';
						t[i+1][j+1]='#';
						t[i+2][j]='#';
					}else{
						cout<<"NO"; return 0;
					}
				}
			}
		}
	}
	if(tot==n*n){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	return 0;
}