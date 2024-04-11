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

int main(){FIN;
	ll h,w; cin>>h>>w;
	char t[h][w];
	fore(i,0,h){
		fore(j,0,w){
			cin>>t[i][j];
		}
	}
	ll maxh=0,hmax=0,maxw=0,wmax=0,tot=0;
	fore(i,0,h){
		ll cont=0;
		fore(j,0,w){
			cont+=(t[i][j]=='*');
			tot+=(t[i][j]=='*');
		}
		if(cont>maxh){
			maxh=cont;
			hmax=i;
		}
	}
	fore(j,0,w){
		ll cont=0;
		fore(i,0,h){
			cont+=(t[i][j]=='*');
		}
		if(cont>maxw){
			maxw=cont;
			wmax=j;
		}
	}
	if(hmax==0||hmax==h-1||wmax==0||wmax==w-1){
		cout<<"NO"; return 0;
	}
	if(t[hmax+1][wmax]=='.'||t[hmax-1][wmax]=='.'||t[hmax][wmax+1]=='.'||t[hmax][wmax-1]=='.'||t[hmax][wmax]=='.'){
		cout<<"NO"; return 0;
	}
	ll totc=(t[hmax][wmax]=='*');
	fore(i,hmax+1,h){
		if(t[i][wmax]=='*'){
			totc++;
		}else{
			break;
		}
	}
	for(int i=hmax-1;i>=0;i--){
		if(t[i][wmax]=='*'){
			totc++;
		}else{
			break;
		}
	}
	fore(j,wmax+1,w){
		if(t[hmax][j]=='*'){
			totc++;
		}else{
			break;
		}
	}
	for(int j=wmax-1;j>=0;j--){
		if(t[hmax][j]=='*'){
			totc++;
		}else{
			break;
		}
	}
	if(totc==tot){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	
	return 0;
}