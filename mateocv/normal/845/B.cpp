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
	string s; cin>>s;
	ll d[6];
	fore(i,0,6){
		d[i]=0+s[i]-'0';
	}
	if(d[0]+d[1]+d[2]==d[3]+d[4]+d[5]){
		cout<<0; return 0;
	}
	fore(i,0,6){
		fore(j,0,10){
			if(d[0]+d[1]+d[2]-(d[3]+d[4]+d[5])+(i>2)*(d[i]-j)+(i<3)*(j-d[i])==0){
				cout<<1; return 0;
			}
		}
	}
	fore(i,0,6){
		fore(ii,0,6){
			if(i==ii)continue;
			fore(j,0,10){
				fore(jj,0,10){
					if(d[0]+d[1]+d[2]-(d[3]+d[4]+d[5])+(i>2)*(d[i]-j)+(i<3)*(j-d[i])+(ii>2)*(d[ii]-jj)+(ii<3)*(jj-d[ii])==0){
						cout<<2; return 0;
					}
				}
			}
		}
	}
	cout<<3;
	
	return 0;
}