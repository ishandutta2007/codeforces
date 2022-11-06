#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll n,m,ta,tb,k;
ll a[200006],b[200006],c[200006];

int main(){FIN;
	cin>>n>>m>>ta>>tb>>k;
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	fore(i,0,n)a[i]+=ta;
	ll l=0,r=0;
	while(r<m){
		if(l==n){
			c[r]=l; r++;
		}else if(b[r]>=a[l])l++;
		else{
			c[r]=l;
			r++;
		}
	}
	//fore(i,0,m)cout<<c[i]<<" "; cout<<"\n";
	ll res=0;
	fore(i,0,k+1){
		auto it=upper_bound(c,c+m,i);
		if(it==c+m){
			cout<<-1; return 0;
		}
		if(it==c){
			if(it+k>=c+m){
				cout<<-1; return 0;
			}
			res=max(res,b[k]+tb);
			//cout<<b[k]+tb<<endl;
		}else{
			if(k-*(it-1)+(it-c)>=m){
				cout<<-1; return 0;
			}
			res=max(res,b[k-*(it-1)+(it-c)]+tb);
			//cout<<b[k-*(it-1)+(it-c)]+tb<<endl;
		}
	}
	cout<<res;
}