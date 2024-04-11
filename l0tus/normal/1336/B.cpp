#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;
const ll INF = 4e18;

ll cal(ll x, ll y, ll z)
{
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}

ll a[MN],b[MN],c[MN];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
    	int na,nb,nc;
    	cin >> na >> nb >> nc;
    	for(int i=0; i<na; i++){
    		cin >> a[i];
    	}
    	for(int i=0; i<nb; i++){
    		cin >> b[i];
    	}
    	for(int i=0; i<nc; i++){
    		cin >> c[i];
    	}
    	sort(a,a+na);
    	sort(b,b+nb);
    	sort(c,c+nc);
    	int x,y,z;
    	ll ans = INF;
    	for(int x=0; x<na; x++){

    		y = lower_bound(b,b+nb,a[x])-b;
    		if(0<=y&&y<nb){
	    		z = lower_bound(c,c+nc,(a[x]+b[y])/2)-c;
	    		///cout << z << '\n';
	    		if(0<=z&&z<nc) ans = min(ans,cal(a[x],b[y],c[z]));
	    		if(0<=z-1&&z-1<nc) ans = min(ans,cal(a[x],b[y],c[z-1]));
	    		if(0<=z+1&&z+1<nc) ans = min(ans,cal(a[x],b[y],c[z+1]));
    		}
    		y--;
    		if(0<=y&&y<nb){
	    		z = lower_bound(c,c+nc,(a[x]+b[y])/2)-c;
	    		///cout << z << '\n';
	    		if(0<=z&&z<nc) ans = min(ans,cal(a[x],b[y],c[z]));
	    		if(0<=z-1&&z-1<nc) ans = min(ans,cal(a[x],b[y],c[z-1]));
	    		if(0<=z+1&&z+1<nc) ans = min(ans,cal(a[x],b[y],c[z+1]));
    		}
      		y+=2;
    		if(0<=y&&y<nb){
	    		z = lower_bound(c,c+nc,(a[x]+b[y])/2)-c;
	    		///cout << z << '\n';
	    		if(0<=z&&z<nc) ans = min(ans,cal(a[x],b[y],c[z]));
	    		if(0<=z-1&&z-1<nc) ans = min(ans,cal(a[x],b[y],c[z-1]));
	    		if(0<=z+1&&z+1<nc) ans = min(ans,cal(a[x],b[y],c[z+1]));
    		}

    		z = lower_bound(c,c+nc,a[x])-c;
    		if(0<=z&&z<nc){
	    		y = lower_bound(b,b+nb,(a[x]+c[z])/2)-b;
	    		///cout << z << '\n';
	    		if(0<=y&&y<nb) ans = min(ans,cal(a[x],b[y],c[z]));
	    		if(0<=y-1&&y-1<nb) ans = min(ans,cal(a[x],b[y-1],c[z]));
	    		if(0<=y+1&&y+1<nb) ans = min(ans,cal(a[x],b[y+1],c[z]));
    		}
    		z--;
    		if(0<=z&&z<nc){
	    		y = lower_bound(b,b+nb,(a[x]+c[z])/2)-b;
	    		///cout << z << '\n';
	    		if(0<=y&&y<nb) ans = min(ans,cal(a[x],b[y],c[z]));
	    		if(0<=y-1&&y-1<nb) ans = min(ans,cal(a[x],b[y-1],c[z]));
	    		if(0<=y+1&&y+1<nb) ans = min(ans,cal(a[x],b[y+1],c[z]));
    		}
    		z+=2;
    		if(0<=z&&z<nc){
	    		y = lower_bound(b,b+nb,(a[x]+c[z])/2)-b;
	    		///cout << z << '\n';
	    		if(0<=y&&y<nb) ans = min(ans,cal(a[x],b[y],c[z]));
	    		if(0<=y-1&&y-1<nb) ans = min(ans,cal(a[x],b[y-1],c[z]));
	    		if(0<=y+1&&y+1<nb) ans = min(ans,cal(a[x],b[y+1],c[z]));
    		}
    	}
    	cout << ans << '\n';
    }
}