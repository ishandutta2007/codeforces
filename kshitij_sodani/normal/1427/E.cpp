
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 
llo x;
vector<pair<llo,pair<llo,llo>>> ans;
llo val(llo xx){
	return __builtin_popcount(xx);
}
llo gcdExtended(llo a, llo b, llo *x, llo *y); 
  
// Function to find modulo inverse of a 
llo  modInverse(llo a, llo m) 
{ 
    llo x, y; 
    llo g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // m is added to handle negative x 
        llo res = (x%m + m) % m; 
        return res;
       // cout << "Modular multiplicative inverse is " << res; 
    } 
} 
  
// C function for extended Euclidean Algorithm 
llo gcdExtended(llo a, llo b, llo *x, llo *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    llo x1, y1; // To store results of recursive call 
    llo gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x;

	//llo kk;
	for(llo jj=0;jj<40;jj++){
		if(x*(1LL<<jj)>(llo)1e18){
			break;
		}
		ans.pb({0,{x*(1LL<<jj),x*(1LL<<jj)}});
	}
	llo ind=-1;
	for(llo jj=19;jj>=0;jj--){
		if(x&(1LL<<jj)){
			ind=jj;
			break;
		}
	}
	ans.pb({1,{x*(1LL<<ind),x}});
	llo y=x^(x*(1LL<<ind));
	//cout<<x<<","<<y<<endl;
	for(llo jj=0;jj<40;jj++){
		if(y*(1LL<<jj)>(llo)1e18){
			break;
		}
		ans.pb({0,{y*(1LL<<jj),y*(1LL<<jj)}});
	}
	//x,pp
	llo kk=(modInverse(x,y)*x)%(x*y);
	if(kk%2==0){
		kk+=x*y;
	}
	llo zz=kk/x;
	llo pp=(kk-1)/y;
	ans.pb({1,{x,x}});
//	cout<<x<<",,,,"<<y<<endl;
//	cout<<kk<<",,,,,,"<<kk-1<<endl;
	llo cur=0;
	for(llo j=0;j<40;j++){
		if((1LL<<j)&zz){
			ans.pb({0,{cur,x*(1LL<<j)}});
			cur+=x*(1LL<<j);
			//cout<<j<<",,";
		}
	}
	//cout<<endl;
	llo cur2=0;
	for(llo j=0;j<40;j++){
		if((1LL<<j)&pp){
			ans.pb({0,{cur2,y*(1LL<<j)}});
			cur2+=y*(1LL<<j);
			//cout<<j<<",,";
		}
	}	
	//cout<<endl;
	ans.pb({1,{cur,cur2}});

	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j.b.a<<" ";
		if(j.a==0){
			cout<<"+ ";
		}
		else{
			cout<<"^ ";
		}
		cout<<j.b.b<<endl;
	}



	return 0;
}