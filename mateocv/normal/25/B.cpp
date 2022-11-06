#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n; cin>>n;
    if(n%2==0){
        char a,b;
        fore(i,0,n/2){
            cin>>a>>b; cout<<a<<b;
            if(i!=n/2-1){cout<<"-";}
        } 
    }else{
        char a,b,c; cin>>a>>b>>c; cout<<a<<b<<c;
        fore(i,0,(n-3)/2){cin>>a>>b; cout<<"-"<<a<<b;}
    }
    
	return 0;
}