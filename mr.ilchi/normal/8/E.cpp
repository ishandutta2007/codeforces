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
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN= 50+5;

int n;
int Pow[MAXN];
ll k;

inline void print (ll v){
	string r;
	while (v){
		r+= (v&1ll)+'0';
		v=(v>>1);
	}
	while ((int)r.size()<n)
		r+='0';
	reverse (r.begin(),r.end());
	cout << r << endl;
}
/*****************************/
inline void setPow (){
	Pow[0]=1;
	for (int i=1;i<=n;i++)
		Pow[i]=Pow[i-1]*2;
}
/*****************************/
inline int Find (int s, int e, int id, int invalid){
	bool test[MAXN];
	memset (test, 0, sizeof test);
	int cnt= 0, cur= 0, Size= (n+1)/2;
	for (int i=1;i< Pow[Size];i ++){
		int p=0;
		while (test[p]){
			cur-= Pow[Size-p-1];
			test[p++]=false;
		}
		test[p]=true;
		cur+= Pow[Size-p-1];
		if (s<= cur && cur<= e && cur!= invalid){
			cnt ++;
			if (cnt== id)
				return i;
		}
	}
	return 0;
}
/*****************************/
inline void even (){
	if (k< Pow[n/2]){
		print (k);
		return;
	}
	k-= (Pow[n/2]-1);
	for (int i=1;i< Pow[n/2-1];i ++){
		int minv=i, maxv= Pow[n/2]-i-1;
		k-= (maxv-minv+1);
		if (k<= 0){
			print(((ll)i)*(Pow[n/2])+Find(minv,maxv,k+(maxv-minv+1), -1));
			return;
		}
	}
	cout << -1 << endl;
}
/*****************************/
inline void odd (){
	if (k< Pow[n/2+1]-1){
		print (k);
		return;
	}
	k-= (Pow[n/2+1]-2);
	for (int i=1;i< Pow[n/2-1];i ++){
		int minv=i, maxv= Pow[n/2]-i-1;
		minv= minv*2, maxv= maxv*2+1;
		int tmp= k, invalid= Pow[n/2+1]-i*2-1;
		k-= (maxv-minv);
		if (invalid < minv || invalid > maxv)
			k --;
		
		if (k<= 0){
			print (((ll)i)*Pow[n/2+1]+Find(minv,maxv,tmp,invalid));
			return;
		}
	}
	cout << -1 << endl;
}
/*****************************/
int main (){
	cin >> n >> k;
	
	setPow ();
	((n&1)==0) ? even() : odd();
	
	return 0;
}