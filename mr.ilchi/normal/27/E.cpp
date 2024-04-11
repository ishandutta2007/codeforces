/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll maxi= 1000000000ll * 1000000000ll; 

ll n, res=maxi;
ll p[]= {2,3,5,7,11,13,17,19,23};


inline int LOG (ll n, ll base){
	int ret=0;
	while (n>=base){
		n/=base; ret++;
	}
	return ret;
}	
/*************************************/
inline ll pw (ll base, ll Pow){
	ll ret=1;
	while (Pow){
		ret*=base; Pow--;
	}
	return ret;
}
/*************************************/
inline void btrack (ll n, ll ans, int index, int past){
	if (res<=ans)
		return;

	if (n==1){
		res= min (res, ans); 
		return;
	}	

	past= min (past, LOG(maxi/ans, p[index]) + 1);

	for (int i=2;i<= past;i ++){
		if (n%i==0){
			btrack (n/i, ans*pw(p[index],i-1), index+1, i);
		}
	}
}
/**********************************/
int main(){
	cin >> n;
	
	btrack (n,1,0,60);

	cout << res << endl;

	return 0;
}